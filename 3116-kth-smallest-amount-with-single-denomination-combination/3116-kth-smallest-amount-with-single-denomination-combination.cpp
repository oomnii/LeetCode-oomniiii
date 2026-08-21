class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto count = [&](ll x) {
            ll total = 0;

            // All non-empty subsets
            for (int mask = 1; mask < (1 << n); mask++) {
                ll lcm = 1;
                int bits = 0;
                bool ok = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        ll g = gcd(lcm, (ll)coins[i]);

                        // avoid overflow
                        lcm = lcm / g * coins[i];

                        if (lcm > x) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok) continue;

                if (bits % 2)
                    total += x / lcm;
                else
                    total -= x / lcm;
            }

            return total;
        };

        ll lo = 1;
        ll hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};