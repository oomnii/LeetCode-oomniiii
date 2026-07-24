class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> firstTwo;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int XOR = nums[i]^nums[j];
                firstTwo.insert(XOR);
            }
        }
        unordered_set<int> full;
        for(auto &it:firstTwo){
            for(int i=0;i<n;i++){
                int XOR = it^nums[i];
                full.insert(XOR);
            }
        }
        return full.size();
    }
};