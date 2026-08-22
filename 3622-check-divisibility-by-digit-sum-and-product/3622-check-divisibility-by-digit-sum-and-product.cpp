class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int product = 1;
        int sum = 0;
        while(n){
            int digit = n%10;
            product *= digit;
            sum += digit;
            n /= 10;
        }
        return num%(sum+product)==0;
    }
};