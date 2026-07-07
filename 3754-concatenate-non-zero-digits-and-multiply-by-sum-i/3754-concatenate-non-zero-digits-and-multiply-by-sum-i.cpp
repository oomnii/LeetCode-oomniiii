class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        int multiple = 1;
        int sum = 0;
        while(n){
            int digit = n%10;
            if(digit!=0){
                num += (1LL*digit*multiple);
                multiple *= 10;
                sum += digit;
            }
            n /= 10;
        }
        return 1LL*sum*num;
    }
};