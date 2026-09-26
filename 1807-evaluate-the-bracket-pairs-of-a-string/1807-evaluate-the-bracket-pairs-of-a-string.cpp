class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto &it : knowledge) {
            mp[it[0]] = it[1];
        }
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(') {
                result += s[i];
            }
            else {
                int j = i + 1;
                string temp = "";

                while (j < s.length() && s[j] != ')') {
                    temp += s[j];
                    j++;
                }
                if (mp.count(temp))
                    result += mp[temp];
                else
                    result += '?';

                i = j;
            }
        }
        return result;
    }
};