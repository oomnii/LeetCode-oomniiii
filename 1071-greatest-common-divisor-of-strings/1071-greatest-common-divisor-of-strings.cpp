class Solution {
public:
    bool check(string &str , string &temp){
        int sz = temp.size();
        for(int i=0;i<str.size();i = i+sz){
            string temp2 = str.substr(i,sz);
            if(temp2!=temp) return false;
        }
        return true;
    } 
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string temp = "";
        vector<string> answers;
        for(int i=0;i<m;i++){
            temp += str2[i];
            if(check(str1,temp) && check(str2,temp)) answers.push_back(temp);
        }
        if(answers.size()==0) return "";
        return answers.back();
    }
};