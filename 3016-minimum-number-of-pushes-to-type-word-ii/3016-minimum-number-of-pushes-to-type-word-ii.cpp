class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto &ch:word){
            freq[ch-'a']++; 
        }

        sort(freq.rbegin(),freq.rend());

        int minPush = 0;
        for(int i=0;i<26;i++){
            if(i<8){
                minPush += freq[i]*1;
            }
            else if(i>=8 && i<16){
                minPush += freq[i]*2;
            }
            else if(i>=16 && i<24){
                minPush += freq[i]*3;
            }
            else minPush += freq[i]*4;
        }
        return minPush;
    }
};