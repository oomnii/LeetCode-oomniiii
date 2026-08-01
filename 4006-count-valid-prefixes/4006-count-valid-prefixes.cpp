class Solution {
public:
    int countValidPrefixes(string s) {
        int count = 0;
        int zeros = 0;
        int ones = 0;
        for(auto &ch:s){
            if(ch=='0') zeros++;
            else ones++;
            if(abs(zeros-ones)<=1) count++; 
        }
        return count;
    }
};