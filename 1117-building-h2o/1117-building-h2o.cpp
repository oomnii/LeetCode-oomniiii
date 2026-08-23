class H2O {
public:
    mutex mtx;
    condition_variable cv;
    int turn = 0;
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        while(turn!=1 && turn!=2){
            cv.wait(lock);
        }
        releaseHydrogen();
        turn = (turn+1)%3;
        lock.unlock();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        while(turn!=0){
            cv.wait(lock);
        }
        releaseOxygen();
        turn = 1 ; 
        lock.unlock();
        cv.notify_all();
    }
};