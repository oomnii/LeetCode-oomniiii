class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int XOR = 0;
        int countZero = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) countZero++;
            XOR = XOR^nums[i];
        }
        if(XOR != 0) return n;
        if(XOR == 0 && countZero==n){
            return 0;
        }
        return n-1;
    }
};