class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves = 0;
        for(int i:nums){
            moves+=nums[nums.size()-1]-i;
        }
        return moves;
    }
};