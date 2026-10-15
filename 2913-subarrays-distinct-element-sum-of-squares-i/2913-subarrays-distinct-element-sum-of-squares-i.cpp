class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            vector<int> v(101,-1);
            int distinct = 0;
            for(int j=i;j<n;j++){
                if(v[nums[j]]==-1){
                    v[nums[j]]++;
                    distinct++;
                }
                sum += (distinct*distinct);
            }
        }
        return sum;
    }
};