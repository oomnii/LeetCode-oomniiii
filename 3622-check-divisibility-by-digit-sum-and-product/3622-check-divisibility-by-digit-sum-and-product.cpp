class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        int product = 1;
        while(n!=0){
            sum +=n%10;
            product *=n%10;
            n = n/10;
        }
        if((num%(sum+product))!=0) return false;
        else return true;
    }
};