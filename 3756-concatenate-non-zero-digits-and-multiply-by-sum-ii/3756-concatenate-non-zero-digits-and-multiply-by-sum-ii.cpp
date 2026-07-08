class Solution {
public:
    int mod = 1e9+7;
    long long power(long long base , long long exp){
        if(exp == 0) return 1;
        long long half = power(base,exp/2);
        long long result = half*half%mod;
        if(exp%2==1) result = result*base%mod;
        return result;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n= s.length();
        vector<int> prefix(n+1,0);
        vector<long long> num(n+1,0);
        vector<int> nonZero(n+1,0);
       
        for(int i=0;i<n;i++){
            int digit = s[i]-'0';
            if(digit == 0){
                prefix[i+1] = prefix[i];
                num[i+1] = num[i];
                nonZero[i+1] = nonZero[i];
            }
            else{
                prefix[i+1] = prefix[i]+digit;
                num[i+1] = ((num[i]*10)%mod+digit)%mod;
                nonZero[i+1] = nonZero[i]+1;
            }
        }

        vector<int> result;

        for(auto &q:queries){
            int l = q[0];
            int r = q[1]+1;
            int diffInDigit = nonZero[r]-nonZero[l];
            long long mul = power(10,diffInDigit);
            long long digit = (num[r] - (num[l] * mul) % mod + mod) % mod;
            long long sum = prefix[r]-prefix[l];
            long long ans = digit*sum%mod;
            result.push_back((int)ans);
        }
        return result;
    }
};