
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 0;

        for(int i = 0; i < n; i++) {
            long long product = 1;
            int g = 0, lcm = 1;

            for(int j = i; j < n; j++) {
                product *= nums[j];
                if(product > 25200) break;

                g = __gcd(g, nums[j]);
                lcm = lcm / __gcd(lcm, nums[j]) * nums[j];

                if(product == 1LL * lcm * g)
                    len = max(len, j - i + 1);
            }
        }
        return len;
    }
};
