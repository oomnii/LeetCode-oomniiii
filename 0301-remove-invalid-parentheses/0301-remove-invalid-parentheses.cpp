class Solution {
public:
    vector<string> ans;
    unordered_set<string> seen;
    int leftRem, rightRem;

    void solve(string &s, int i, int balance, string &temp) {

        if (i == s.size()) {
            if (balance == 0 && leftRem == 0 && rightRem == 0) {
                if (!seen.count(temp)) {
                    seen.insert(temp);
                    ans.push_back(temp);
                }
            }
            return;
        }

        char ch = s[i];

        // Delete '('
        if (ch == '(' && leftRem > 0) {
            leftRem--;
            solve(s, i + 1, balance, temp);
            leftRem++;
        }

        // Delete ')'
        if (ch == ')' && rightRem > 0) {
            rightRem--;
            solve(s, i + 1, balance, temp);
            rightRem++;
        }

        // Keep current character
        if (ch == '(') {
            temp.push_back(ch);
            solve(s, i + 1, balance + 1, temp);
            temp.pop_back();
        }
        else if (ch == ')') {
            if (balance > 0) {
                temp.push_back(ch);
                solve(s, i + 1, balance - 1, temp);
                temp.pop_back();
            }
        }
        else {
            temp.push_back(ch);
            solve(s, i + 1, balance, temp);
            temp.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        leftRem = rightRem = 0;

        // Find minimum number of deletions
        for (char ch : s) {

            if (ch == '(') {
                leftRem++;
            }
            else if (ch == ')') {

                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        string temp;
        solve(s, 0, 0, temp);

        return ans;
    }
};