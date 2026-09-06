class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i=0;
        int j=0;
        vector<int> total;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                total.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                total.push_back(nums2[j]);
                j++;
            }
            else{
                total.push_back(nums1[i]);
                total.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        while(i<n){
            total.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            total.push_back(nums2[j]);
            j++;
        }
        if((n+m)%2==1){
            return (double)total[(n+m)/2];
        }
        return ((double)total[(n+m)/2] + (double)total[(n+m)/2 - 1])/2;
    }
};