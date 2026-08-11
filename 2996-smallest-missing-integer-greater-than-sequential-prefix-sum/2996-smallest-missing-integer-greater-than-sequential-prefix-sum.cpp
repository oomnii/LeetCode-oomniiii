class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st = {nums.begin(),nums.end()};
        int i = 1;
        int sum = nums[0];
        while(i<n){
            if(nums[i]-1==nums[i-1]){
                sum += nums[i];
                i++;
            }
            else break;
        }
        while(1){
            if(st.count(sum)) sum++;
            else return sum;
        }
        return sum;
    }
};