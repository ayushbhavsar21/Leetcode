class Solution {
public:
    bool solve(vector<int>& v, int n,int used,int count,int curr,int side,unordered_map<int,bool>& memo){
        if(count == 4)
            return true;

        if(memo.count(used))    return memo[used];

        for(int i=0;i<n;i++){
            int bit = 1 << i;

            if((used & bit) == 0){
                int news = curr + v[i];

                if(news == side){
                    if(solve(v , n , used | bit , count +1, 0 , side , memo)){
                        return memo[used] = true;
                    }
                }
                else if(news < side){
                    if(solve(v , n , used | bit , count , news , side , memo))
                        return memo[used] = true;
                }
            }
        }
        return memo[used] = false;
    }
    
    bool makesquare(vector<int>& v) {
        long sum = accumulate(v.begin(),v.end(),0L);
        if(sum % 4 != 0)
            return 0;

        int side = sum / 4;

        sort(v.rbegin(), v.rend());
        if(v[0] > side)
            return 0;

        unordered_map<int,bool> memo;

        return solve(v , v.size() , 0 , 0 , 0 , side , memo);
    }
};