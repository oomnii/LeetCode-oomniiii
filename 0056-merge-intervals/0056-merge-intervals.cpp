class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        int i=0;
        while(i<n){
            int j = j+1;
            int prevEnd = intervals[i][1]; 
            while(j<n && intervals[j][0]<=prevEnd){
                prevEnd = max(prevEnd,intervals[j][1]);
                j++;    
            }
            result.push_back({intervals[i][0],prevEnd});
            i = j;
        }
        return result;
    }
};