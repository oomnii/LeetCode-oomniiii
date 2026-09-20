class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int i = 1;
        for(auto &ch:s){
            sum += ((26-(ch-'a'))*i);
            i++;
        }
        return sum; 
    }
};