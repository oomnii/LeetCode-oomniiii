class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {

        unordered_set<int> st(nums.begin(), nums.end());

        vector<vector<int>> result;

        int start = -1;

        for(int i = lower; i <= upper; i++) {

            if(!st.count(i)) {
                if(start == -1)
                    start = i;
            }
            else {
                if(start != -1) {
                    result.push_back({start, i - 1});
                    start = -1;
                }
            }
        }
        if(start != -1)
            result.push_back({start, upper});

        return result;
    }
};