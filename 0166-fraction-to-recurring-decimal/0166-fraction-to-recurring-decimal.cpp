#define ll long long
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";

        bool neg = (numerator < 0) ^ (denominator < 0);
        ll d = abs((ll)denominator);
        ll n = abs((ll)numerator);

        ll x = n/d;
        ll r = n%d;

        string s = (neg ? "-":"") + to_string(n/d);
        if(r==0){
            return s;
        }

        s += ".";

        string f = "";
        unordered_map<ll,int> mp;

        while( r != 0){
            if(mp.count(r)){
                f.insert(mp[r],"(");
                f += ")";
                break;
            }
            mp[r] = f.size();
            r *= 10;
            f += to_string(r/d);
            r %= d;
        }
        s += f;
        return s;
    }
};