class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.rbegin(),nums.rend());
        int i=0;
        int j=n-1;
        long long sum = 0;
        while(i<=j){
            if(i==j) sum += 1LL*nums[i]*nums[i];
            else{
                sum += 1LL*nums[i]*nums[i];
                sum -= 1LL*nums[j]*nums[j];
            }
            i++;
            j--;
        }
        return sum;
    }
};