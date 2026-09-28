class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxi = 0;
        for(auto &it:s){
            if(it=='('){
                cnt++;
                maxi = max(maxi,cnt);
            }
            else if(it==')') cnt--;
        }
        return maxi;
    }
};