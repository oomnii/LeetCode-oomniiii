class Solution {
public:
    int n;
    bool check(vector<int>& weights,int currCap, int days){
        int dayReq = 0;
        for(int i=0;i<n;){
            int cap = 0;
            int j = i;
            while(j<n && cap+weights[j]<=currCap){
                cap += weights[j];
                j++;
            }
            dayReq++;
            i = j;
        }
        return dayReq<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        n = weights.size();
        int mini = *max_element(weights.begin(),weights.end());
        int maxi = INT_MAX;
        int minCap = maxi;
        while(mini<=maxi){
            int currCap = mini+(maxi-mini)/2;
            if(check(weights,currCap,days)){
                minCap = currCap;
                maxi = currCap-1;
            }
            else{
                mini = currCap+1;
            }
        }
        return minCap;
    }
};