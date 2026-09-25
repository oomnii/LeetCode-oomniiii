class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int intersect = 0;
        for(int i=0;i<n;i++){
            int lastPoint = intervals[i][1];
            int str = i+1;
            int end = n-1;
            int range = -1;
            while(str<=end){
                int mid = str + (end-str)/2;
                if(intervals[mid][0]<=lastPoint){
                    range = mid;
                    str = mid+1;    
                }
                else end = mid-1;
            }
            if(range!=-1) intersect += range-i;
        }
        return intersect;
    }
};