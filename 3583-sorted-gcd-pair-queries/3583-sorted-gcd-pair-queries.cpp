#define ll long long int

class Solution {
public:
    vector<int> gcdValues(vector<int>& v, vector<long long>& q) {
        int n = v.size();
        int maxi = *max_element(v.begin() , v.end());

        vector<ll> count(maxi + 1, 0);

        for(auto it:v){
            for(int i=1;i*i <= it ;i++){
                if(it%i == 0 ){
                    count[i]++;
                    if(i*i != it){
                        count[it / i]++;
                    }
                } 
            }
        }

        for(auto it :count)
            cout<<it<<" ";
        cout<<endl;

        vector<ll> gcd(maxi + 1,0);

        for(int i=maxi;i>0;i--){
            ll c = count[i];
            gcd[i] = c * (c-1) / 2;

            for(int j = 2*i;j<=maxi;j += i){
                gcd[i] -= gcd[j];
            }
        }
        for(auto it :gcd)
            cout<<it<<" ";
        cout<<endl;

        vector<ll> prefix(maxi + 1 , 0);

        for(int i=1;i<=maxi;i++){
            prefix[i] = gcd[i] + prefix[i-1];
        }

        for(auto it :prefix)
            cout<<it<<" ";
        cout<<endl;

        vector<int> ans;

        for(auto it:q){
            ll l = 1,r = maxi , result = -1;

            while(l <= r){
                ll mid = (l + r) /2 ; 

                if(prefix[mid] > it){
                    result = mid;
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            ans.push_back(result);
        }
        return ans;

    }
};