class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        int alice = 0;
        int bob = 0;
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(rain[i]==0) ans.push_back("None");
            else if(rain[i]==1 && i+1<n && rain[i+1]==1){
                if(alice<=bob) {
                    ans.push_back("Alice");
                    alice++;
                }
                else{
                    ans.push_back("Bob");
                    bob++;
                }
            }
            else {
                ans.push_back("Bob");
                bob++;
            }
        }
        return ans;
    }
};