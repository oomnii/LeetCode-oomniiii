class Solution {
public:
    bool check(int n,int t){
        int currP = 1;
        while(n){
            int digit = n%10;
            currP *= digit;
            n /= 10;
        }
        if(currP%t==0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        while(1){
            if(check(n,t)) return n;
            n++;
        }
        return n;
    }
};