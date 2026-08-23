class Foo {
public:
    mutex mtx;
    condition_variable cv;
    int stage = 0;

    Foo() {}

    void first(function<void()> printFirst) {
        printFirst();
        {
            lock_guard<mutex> lock(mtx);
            stage = 1;
        }

        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() {
                return stage >= 1;
            });
        }

        printSecond();
        {
            lock_guard<mutex> lock(mtx);
            stage = 2;
        }
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() {
                return stage >= 2;
            });
        }
        printThird();
    }
};