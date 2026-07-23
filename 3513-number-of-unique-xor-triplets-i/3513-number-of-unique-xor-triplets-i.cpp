class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2) return n;
        for(int i=2;i<31;i++){
            int power = 1<<i;
            if(power>n) return power;
        }
        return -1;
    }
};