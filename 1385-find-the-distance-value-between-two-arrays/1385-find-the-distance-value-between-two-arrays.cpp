class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int num = arr1[i];
            bool valid = true;
            for(int j=0;j<m;j++){
                if(abs(num-arr2[j])<=d){
                    valid = false;
                    break;
                }
            }
            if(valid) cnt++;
        }
        return cnt;
    }
};