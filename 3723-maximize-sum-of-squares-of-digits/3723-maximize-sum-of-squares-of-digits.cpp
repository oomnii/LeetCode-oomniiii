class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(sum){
            int digit = 0;
            if(sum>=9){
                digit = 9;
                sum -= 9;
            }
            else{
                digit = sum;
                sum = 0;
            }
            ans += to_string(digit);
            if(ans.length()>num) return "";
        }
        while(ans.length()<num){
            ans += '0';
        }
        return ans;
    }
};