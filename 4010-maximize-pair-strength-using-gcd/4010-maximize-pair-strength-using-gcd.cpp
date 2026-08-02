class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long strength = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                long long mul = 1LL*nums[i]*nums[j];
                int GCD = __gcd(nums[i],nums[j]);
                long long GCDsquare = 1LL*GCD*GCD;
                long long currS = (mul/GCDsquare);
                strength = max(strength,currS);
            }
        }
        return strength;
    }
};