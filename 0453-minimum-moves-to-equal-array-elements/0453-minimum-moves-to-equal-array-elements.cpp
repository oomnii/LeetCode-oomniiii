class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int moves = 0;
        int currMoves = nums[n-1]-nums[0];
        for(int i=n-1;i>0;i--){
            moves += currMoves;
            int diff = nums[i]-nums[i-1];
            currMoves -= diff;
        }
        return moves;
    }
};

/*
{1,2,3,4,5}->{5,6,7,8,5}->{8,9,10,8,8}->{10,11,10,10,10}-{11,11,11,11,11}
4+3+2+1 = 10

{7,9,4,2,5,9,3}->{14,16,11,9,12,9,10}->{21,16,18,16,19,16,17}->{21,21,23,21,24,21,22}->
{24,24,26,24,24,25}->{26,26,26,26,26,27}->{27,27,27,27,27,27,27}
7+7+5+3+2+1 = 25

{2,2,5,7,7}->{7,7,10,12,7}->{12,12,15,12,12}->{15,15,15,15,15}
5+5+3 = 13
*/