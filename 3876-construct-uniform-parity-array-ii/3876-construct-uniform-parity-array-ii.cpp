class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;
        for(auto &it:nums1){
            if(it%2==0){
                minEven = min(minEven,it);
            }
            else{
                minOdd = min(minOdd,it);
            }
        }
        if(minOdd==INT_MAX) return true;
        if(minEven==INT_MAX) return true;
        if(minOdd<minEven) return true;
        return false;
    }
};