class Foo {
public:
    atomic<bool> firstDone{false};
    atomic<bool> secondDone{false};

    Foo() {}

    void first(function<void()> printFirst) {
        printFirst();
        firstDone = true;
    }

    void second(function<void()> printSecond) {
        while (!firstDone) {
            this_thread::yield();
        }

        printSecond();
        secondDone = true;
    }

    void third(function<void()> printThird) {
        while (!secondDone) {
            this_thread::yield();
        }

        printThird();
    }
};