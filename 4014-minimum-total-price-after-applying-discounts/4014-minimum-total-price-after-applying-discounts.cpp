class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        double price = 0;
        for(int i=0;i<n;i++){
            if(i>=m) price = price + (double)prices[i];
            else{
                double currAmount = (double)prices[i]*(100-discounts[i])/100.0;
                price += currAmount;
            }
        }
        return price;
    }
};