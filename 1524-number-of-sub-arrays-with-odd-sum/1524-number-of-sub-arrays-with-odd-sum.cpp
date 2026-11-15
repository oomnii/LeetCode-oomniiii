class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9+7;
        int totalSubarrays = 0;
        int odd = 0;
        int even = 0;

        vector<int> prefix(n);
        prefix[0] = nums[0];

        if(prefix[0]%2==1) odd++;
        else even++;

        totalSubarrays += odd;

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
            if(prefix[i]%2==0){
                totalSubarrays = (totalSubarrays + odd)%mod;
            }
            else{
                totalSubarrays = (totalSubarrays + even + 1)%mod;
            }
            if(prefix[i]%2==1) odd++; 
            else even++;
        }
        return totalSubarrays;
    }
};