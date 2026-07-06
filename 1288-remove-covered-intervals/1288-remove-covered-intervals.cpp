class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];   // Descending
            return a[0] < b[0];       // Ascending
        });
        unordered_set<int> deleted;
        for(int i=0;i<n;i++){
            if(deleted.count(i)) continue;
            int currStr = intervals[i][0];
            int currEnd = intervals[i][1];
            int j = i+1;
            while(j<n && intervals[j][0]<=currEnd){
                if(intervals[j][1]<=currEnd){
                    deleted.insert(j);
                }
                j++;
            }
        }
        return n-deleted.size();
    }
};