class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string temp = "";
        int cntY = 0;
        for(auto &it:s){
            if(it==y) cntY++;
            else temp += it;
        }
        string prefix = "";
        while(cntY--) prefix += y;
        return prefix+temp;
    }
};