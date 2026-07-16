class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGCD;
        int maxi = nums[0];
        for(auto &it:nums){
            maxi = max(maxi,it);
            prefixGCD.push_back(__gcd(it,maxi));
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        int i=0;
        int j=n-1;
        long long sum = 0;
        while(i<j){
            long long curr = __gcd(prefixGCD[i],prefixGCD[j]);
            sum += curr;
            i++;
            j--;
        }
        return sum;
    }
};