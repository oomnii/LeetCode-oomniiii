class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int str = -1;
        int end = n;
        int l = 0;
        int r = n-1;
        // lower side:
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>target){
                r = mid-1;
            }
            else if(nums[mid]<target){
                l = mid+1;
            }
            else{
                r = mid-1;
                str = mid;
            }
        }
        // upper side:
        l = 0;
        r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>target){
                r = mid-1;
            }
            else if(nums[mid]<target){
                l = mid+1;
            }
            else{
                l = mid+1;
                end = mid;
            }
        }
        if(str == -1 && end == n) return {-1,-1};
        return {str,end};

    }
};