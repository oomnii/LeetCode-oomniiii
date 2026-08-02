class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int valid = 0;
        float ratio = (float)a/(float)b;
        for(int i=0;i<n;i++){
            float x = 0.0;
            float y = 0.0;
            for(int j=i;j<n;j++){
                if(nums[j]&1) y = y+1.0;
                else x = x+1.0;
                if(y==0) continue;
                float curr = x/y;
                if(curr<=ratio) valid++;
            }
        }
        return valid;
    }
};