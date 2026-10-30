class Solution {
public:
    int rearrange(int num) {
        string temp = to_string(num);
        sort(temp.rbegin(), temp.rend());
        return stoi(temp);
    }

    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            int num = rearrange(nums[i]);
            v.push_back({num - nums[i], nums[i]});
        }
        sort(v.rbegin(), v.rend());

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(k > 0 && v[i].first > 0) {
                sum += v[i].second + v[i].first;
                k--;
            }
            else {
                sum += v[i].second;
            }
        }
        return sum;
    }
};