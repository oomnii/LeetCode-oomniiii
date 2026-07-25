class Solution {
public:
    int maxProduct(int n) {
        int m1 = 0;
        int m2 = 0;
        while(n){
            int digit = n%10;
            if(digit>=m1){
                m2 = m1;
                m1 = digit;
            }
            if(digit>=m2 && digit < m1){
                m2 = digit;
            }
            n /= 10;
        }
        return m1*m2;
    }
};