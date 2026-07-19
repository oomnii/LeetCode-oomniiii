class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }

        vector<bool> present(26,false);
        stack<char> st;

        for(auto &ch:s){
            freq[ch-'a']--;
            if (present[ch - 'a']) {
                continue;
            }
            while(!st.empty() && st.top()>ch && freq[st.top()-'a']>0){
                present[st.top()-'a'] = false;
                st.pop();
            }
            st.push(ch);
            present[ch-'a'] = true;   
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};