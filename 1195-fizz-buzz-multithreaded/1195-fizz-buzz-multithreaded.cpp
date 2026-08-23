class FizzBuzz {
private:
    int n;
    int turn = 1;

    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    void fizz(function<void()> printFizz) {
        for (int i = 1; i <= n; i++) {

            if (i % 3 == 0 && i % 5 != 0) {
                unique_lock<mutex> lock(mtx);

                while (turn != i) {
                    cv.wait(lock);
                }

                printFizz();
                turn++;

                lock.unlock();
                cv.notify_all();
            }
        }
    }

    void buzz(function<void()> printBuzz) {
        for (int i = 1; i <= n; i++) {

            if (i % 3 != 0 && i % 5 == 0) {
                unique_lock<mutex> lock(mtx);

                while (turn != i) {
                    cv.wait(lock);
                }

                printBuzz();
                turn++;

                lock.unlock();
                cv.notify_all();
            }
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 1; i <= n; i++) {

            if (i % 15 == 0) {
                unique_lock<mutex> lock(mtx);

                while (turn != i) {
                    cv.wait(lock);
                }

                printFizzBuzz();
                turn++;

                lock.unlock();
                cv.notify_all();
            }
        }
    }

    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {

            if (i % 3 != 0 && i % 5 != 0) {
                unique_lock<mutex> lock(mtx);

                while (turn != i) {
                    cv.wait(lock);
                }

                printNumber(i);
                turn++;

                lock.unlock();
                cv.notify_all();
            }
        }
    }
};