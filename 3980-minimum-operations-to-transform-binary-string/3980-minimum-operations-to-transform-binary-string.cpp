class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        long long cntX = 0;
        long long cntY = 0;
        long long b = 0;
        int run = 0;
        for(int i=0;i<n;++i){
            if(s1[i]=='1' && s2[i]=='0'){
                cntX++;
                run++;
            }
            else{
                if(run) b+= (run+1)/2;
                run = 0;
                if(s1[i]=='0' && s2[i]=='1') cntY++;
            }
        }
        if(run) b += (run+1)/2;
        if(n==1 && cntX>0) return -1;
        return (int)(3*b+cntY-cntX);
    }
};