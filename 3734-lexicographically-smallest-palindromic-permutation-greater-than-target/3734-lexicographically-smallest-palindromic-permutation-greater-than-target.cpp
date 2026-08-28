class Solution {
public:
    int sz;
    char oddCh = '$';
    string result="";
    bool solve(string curr,vector<int> &freq,string &target,int i,bool greater){
        if (i == sz) {
            string candidate = curr;
            string rightHalf = candidate;
            reverse(begin(rightHalf), end(rightHalf));
            
            if(oddCh != '$')
                candidate += oddCh;

            candidate += rightHalf;

            if (candidate > target) {
                result = candidate;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[i])
                continue;
            // Do: 
            curr.push_back(ch);
            freq[ch - 'a']--;

            bool isGreater = greater || ch > target[i];
            // Explore:
            if (solve(curr, freq, target, i + 1, isGreater))
                return true;
            // Undo:
            curr.pop_back();
            freq[ch - 'a']++;
        }
        return false;
    }  
   
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        int odd = 0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){
                oddCh = 'a'+i;
                odd++;
            }
            freq[i] = freq[i]/2;
        }
        if(odd>1) return "";
        
        sz = target.size()/2;
        string curr;
        solve(curr,freq,target,0,false);
        return result;
    }
};