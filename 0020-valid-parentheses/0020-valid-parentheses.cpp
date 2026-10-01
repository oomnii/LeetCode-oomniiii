class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2) return false;

        stack<char> st;
        for(auto &it:s){
            if(it=='(' || it=='{' || it=='[') st.push(it);
            else if(st.empty()) return false;
            else if(it==')'){
                if(st.top()=='(') st.pop();
                else return false;
            }
            else if(it=='}'){
                if(st.top()=='{') st.pop();
                else return false;
            }
            else if(it==']'){
                if(st.top()=='[') st.pop();
                else return false;
            }
        }
        return st.size()==0;
    }
};