class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    ll power(ll base ,ll exp){
        if (exp == 0) return 1;
        ll half = power(base,exp/2);
        ll result = (half*half)%mod;
        if(exp%2==1) result = (result*base)%mod;
        return result;
    }
    int sumDecoded(vector<long long>& nums) {
        ll sum = 0;
        for(auto &num:nums){
            ll w = num%10;
            ll d = num/10;
            string temp = to_string(d);
            ll x = stoll(temp.substr(0,w));
            ll y = stoll(temp.substr(w,temp.size()-w));
            ll decodeVal = power(x,y);
            sum = (sum+decodeVal)%mod;
        }
        return (int)sum;
    }
};