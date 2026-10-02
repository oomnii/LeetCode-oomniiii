class Solution {
public:
    vector<string> ans;

    bool check(string &temp) {
        int cnt = 0;
        for(char ch : temp) {
            if(ch == '(') cnt++;
            else cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }

    void solve(string &temp, int open, int close, int n) {
        if(temp.size() == 2*n) {
            ans.push_back(temp);
            return;
        }

        // Add '('
        if(open < n) {
            temp += '(';
            solve(temp, open + 1, close, n);
            temp.pop_back();
        }

        // Add ')'
        if(close < open) {
            temp += ')';
            solve(temp, open, close + 1, n);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        ans.clear();
        string temp = "";
        solve(temp, 0, 0, n);
        return ans;
    }
};