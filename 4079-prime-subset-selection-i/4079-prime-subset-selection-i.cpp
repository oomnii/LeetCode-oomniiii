
class Solution {
public:
    bool checkPrime(int num) {
        if (num < 2) return false;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        int sum = 0;

        for (int i = 2; i <= n; i++) {
            if (checkPrime(i)) {
                if (sum + i > s) break;

                sum += i;
                ans.push_back(i);
            }
        }

        return ans;
    }
};
