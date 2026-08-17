class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxi(n);
        maxi[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxi[i] = max(maxi[i+1],prices[i]);
        }
        int maxProfit = 0;
        for(int i=0;i<n;i++){
            int curr = prices[i];
            int maxPro = maxi[i];
            maxProfit = max(maxProfit,maxPro-curr);
        }
        return maxProfit;
    }
};