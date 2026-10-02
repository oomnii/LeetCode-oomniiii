class Solution {
public:
    vector<string> ans;

    bool check(string &temp) {
        int cnt = 0;

        for(auto &it : temp) {
            if(it == '(') cnt++;
            else cnt--;

            if(cnt < 0) return false;
        }

        return cnt == 0;
    }

    void solve(string &temp, int open, int n) {
        if(temp.size() == 2*n) {
            if(check(temp))
                ans.push_back(temp);
            return;
        }

        // Do '('
        if(open < n) {
            temp += '(';
            open++;

            // Explore
            solve(temp, open, n);

            // Undo
            temp.pop_back();
            open--;
        }

        // Do ')'
        temp += ')';

        // Explore
        solve(temp, open, n);

        // Undo
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(temp, 0, n);
        return ans;
    }
};