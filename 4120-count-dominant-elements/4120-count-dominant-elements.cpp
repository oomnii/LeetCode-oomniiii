class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            double sum = 0;
            double nbr = 0;
            if(i-1>=0){
                sum += nums[i-1];
                nbr += 1;
            }
            if(i+1<n){
                sum += nums[i+1];
                nbr += 1;
            }
            if(sum == 0) count++;
            else if(sum/nbr <= (double)nums[i]) count++;
        }
        return count;
    }
};