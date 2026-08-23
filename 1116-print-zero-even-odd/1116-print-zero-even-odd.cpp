class ZeroEvenOdd {
private:
    int n;

    mutex mtx;
    condition_variable cv;

    // 0 = zero's turn
    // 1 = odd's turn
    // 2 = even's turn
    int turn = 0;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [&]() {
                return turn == 0;
            });

            printNumber(0);

            if (i % 2 == 1)
                turn = 1;
            else
                turn = 2;

            lock.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [&]() {
                return turn == 2;
            });

            printNumber(i);
            turn = 0;

            lock.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [&]() {
                return turn == 1;
            });

            printNumber(i);
            turn = 0;

            lock.unlock();
            cv.notify_all();
        }
    }
};