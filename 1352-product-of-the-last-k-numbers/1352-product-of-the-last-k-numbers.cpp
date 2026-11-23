
class ProductOfNumbers {
public:
    vector<int> multiple;

    ProductOfNumbers() {
        multiple.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            multiple.clear();
            multiple.push_back(1);
        } else {
            multiple.push_back(multiple.back() * num);
        }
    }

    int getProduct(int k) {
        int sz = multiple.size();

        if (k >= sz) return 0;

        return multiple[sz - 1] / multiple[sz - k - 1];
    }
};


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */