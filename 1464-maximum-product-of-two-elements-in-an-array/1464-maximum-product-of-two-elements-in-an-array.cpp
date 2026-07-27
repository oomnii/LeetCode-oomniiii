class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 0;
        int mx2 = 0;
        for(auto &it:nums){
            if(it>=mx1){
                mx2 = mx1;
                mx1 = it;
            }
            if(it<mx1 && it>mx2) mx2 = it;
        }
        return (mx1-1)*(mx2-1);
    }
};