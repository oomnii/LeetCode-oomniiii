class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int turn = 0;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[&](){
                return turn==0;
            });
            printFoo();
        	turn = 1;
            lock.unlock();
            cv.notify_all();  	
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[&](){
                return turn==1;
            });
            printBar();
        	turn = 0;
            lock.unlock();
            cv.notify_all();
        }
    }
};