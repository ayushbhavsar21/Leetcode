#define ll long long
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<ll> ugly(n, 1); 
        int k = primes.size();   
        vector<int> idx(k, 0);   
        vector<ll> val ;
        for(auto it:primes){
            val.push_back((ll)(it));
        } 
        
        for (int i = 1; i < n; i++) {
            int nextUgly = *min_element(val.begin(), val.end());
            ugly[i] = nextUgly;

            for (int j = 0; j < k; j++) {
                if (val[j] == nextUgly) {
                    idx[j]++; 
                    val[j] = primes[j] * ugly[idx[j]];
                }
            }
        }
        return ugly[n - 1];
    }
};
