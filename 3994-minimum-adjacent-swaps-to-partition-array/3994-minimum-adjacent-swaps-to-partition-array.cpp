class Solution {
public:
    int mod = 1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        long long oper = 0;
        int i = 0;
        int j = 0;
        // making first part (<a) ;
        while(j<n){
            if(nums[j]<a){
                oper = (oper+(j-i))%mod;
                i++;
            }
            j++;
        }
        
        // making second part ([a,b]);
        i = 0;
        j = 0;
        for (int k = 0; k < n; k++) {
            if (nums[k] >= a) {
                if (nums[k] <= b) {
                    oper = (oper + (j - i)) % mod;
                    i++;
                }
                j++;
            }
        }

        // third part is automatically made:
        return oper;
    }
};