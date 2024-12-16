class Solution {
public:
    
    struct VectorHash {
        unsigned int operator()(const vector<int>& v) const {
            unsigned int hash = 0;
            for (int num : v) {
                hash = hash * 31 + num; 
            }
            return hash;
        }
    };

    int dfs(vector<int>& p, vector<vector<int>>& sp, vector<int>& v, unordered_map<vector<int>, int, VectorHash>& memo) {
        if (memo.count(v))
            return memo[v];

        
        int cost = 0;
        for (int i = 0; i < v.size(); i++) {
            cost += v[i] * p[i];
        }

        
        for (auto& offer : sp) {
            vector<int> updatedv = v;
            bool valid = true;

            
            for (int i = 0; i < v.size(); i++) {
                updatedv[i] -= offer[i];
                if (updatedv[i] < 0) {
                    valid = false; 
                    break;
                }
            }

            if (valid) {
                cost = min(cost, offer.back() + dfs(p, sp, updatedv, memo));
            }
        }

        return memo[v] = cost;
    }

    int shoppingOffers(vector<int>& p, vector<vector<int>>& sp, vector<int>& v) {
        
        for (auto it = sp.begin(); it != sp.end();) {
            int sum = 0;
            for (int i = 0; i < p.size(); i++) {
                sum += (*it)[i] * p[i];
            }
            if (sum <= (*it).back()) {
                it = sp.erase(it); 
            } else {
                ++it;
            }
        }

        
        unordered_map<vector<int>, int, VectorHash> memo;
        return dfs(p, sp, v, memo);
    }
};
