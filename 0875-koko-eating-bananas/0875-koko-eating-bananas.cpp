class Solution {
public:
    bool check(vector<int>& piles, int h,int speed){
        int n = piles.size();
        int totalH = 0;
        for(int i=0;i<n;i++){
            totalH += (piles[i]+speed-1)/speed;
            if(totalH>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(),piles.end());
        int mini = 1;
        int speed = maxi;
        while(mini<=maxi){
            int currS = mini+(maxi-mini)/2;
            if(check(piles,h,currS)){
                speed = currS;
                maxi = currS-1;
            }
            else{
                mini = currS+1;
            }
        }
        return speed;
    }
};