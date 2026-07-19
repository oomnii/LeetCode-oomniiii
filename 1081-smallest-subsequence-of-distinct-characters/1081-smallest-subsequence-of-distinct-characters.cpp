class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }

        vector<bool> present(26,false);
        string result = "";

        for(auto &ch:s){
            freq[ch-'a']--;
            if (present[ch - 'a']) {
                continue;
            }
            while(result.size()!=0 && result.back()>ch && freq[result.back()-'a']>0){
                present[result.back()-'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            present[ch-'a'] = true;   
        }
        return result;
    }
};