class Solution {
public:
    bool canAliceWin(int n) {
        int str = 10;
        int chance = 0;
        while(n != -1){
            if(n>=str){
                n -= str;
                str--;
                chance ^= 1; 
            }
            else{
                if(chance == 0) return false;
                else return true;
            }
        }
        return false;
    }
};