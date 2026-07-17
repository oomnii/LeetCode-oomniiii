class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int m = queries.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> divCount(maxi+1,0);
        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int j=1;j*j<=num;j++){
                if(num%j==0){
                    divCount[j]++;
                    if(num/j!=j) divCount[num/j]++;
                }
            }
        }

        vector<long long> actualPairs(maxi+1,0);
        for(int i=maxi;i>=1;i--){
            long long currPair = 1LL*divCount[i]*(divCount[i]-1)/2;
            for(int j=i*2;j<=maxi;j+=i){
                currPair -= actualPairs[j];
            }
            actualPairs[i] = currPair;
        }

        vector<long long> prefixCount(maxi+1,0);
        for(int i=1;i<=maxi;i++){
            prefixCount[i] = prefixCount[i-1] + actualPairs[i];
        }

        vector<int> result;
        for(int i=0;i<m;i++){
            long long idx = queries[i];
            int l = 1;
            int r = maxi;
            int temp = 1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(prefixCount[mid]>idx){
                    temp = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
            result.push_back(temp);
        }
        return result;
    }
};