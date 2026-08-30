class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> result;
        for (int num : nums) {
            char curr = 'a';
            string temp = "";
            while (num) {
                if (num % 2 == 1) temp += curr;
                num /= 2;
                curr++;
                if (curr == 'z') {
                    while (num--) {
                        temp += curr;
                    }
                }
            }
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
        }
        return result;
    }
};