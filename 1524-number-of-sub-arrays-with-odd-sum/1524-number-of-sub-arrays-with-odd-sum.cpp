class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9+7;
        int totalSubarrays = 0;
        int odd = 0;
        int even = 0;
        int sum = nums[0];

        if(sum%2==1) odd++;
        else even++;

        totalSubarrays += odd;

        for(int i=1;i<n;i++){
            sum += nums[i];
            if(sum%2==0){
                totalSubarrays = (totalSubarrays + odd)%mod;
            }
            else{
                totalSubarrays = (totalSubarrays + even + 1)%mod;
            }
            if(sum%2==1) odd++; 
            else even++;
        }
        return totalSubarrays;
    }
};