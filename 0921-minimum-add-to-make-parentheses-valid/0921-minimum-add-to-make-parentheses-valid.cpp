class Solution {
public:
    int minAddToMakeValid(string s) {
        int minAdd = 0;
        int cnt = 0;
        for(auto &it:s){
            if(it=='(') cnt++;
            else cnt--;
            if(cnt<0){
                minAdd++;
                cnt++;
            }
        }
        minAdd += cnt;
        return minAdd;
    }
};