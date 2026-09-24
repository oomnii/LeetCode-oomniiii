class Solution {
public:
    int check(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==check(nums[i])) return i;
        }
        return -1;
    }
};