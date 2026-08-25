class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int need = k;
        while(i<n){
            if(nums[i]<need) i++;
            else if(nums[i]==need){
                need += k;
                i++;
            }
            else{
                return need;
            }
        }
        return need;
    }
};