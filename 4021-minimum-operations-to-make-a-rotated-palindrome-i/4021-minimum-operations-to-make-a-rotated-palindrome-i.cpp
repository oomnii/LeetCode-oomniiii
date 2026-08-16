class Solution {
public:
    string temp;
    int check(int str , int end){
        int oper = 0;
        while(str<=end){
            if(temp[str]!=temp[end]){
                int diff = abs(temp[str]-temp[end]);
                oper += min(diff,26-diff);
            }
            str++;
            end--;
        }
        return oper;
    }
    int minOperations(string s) {
        int n = s.length();
        temp = s+s;
        int minOper = INT_MAX;
        int i=0;
        int j=n-1;
        while(j<2*n){
            minOper = min(minOper,i+check(i,j));
            i++;
            j++;
        }
        return minOper;
    }
};