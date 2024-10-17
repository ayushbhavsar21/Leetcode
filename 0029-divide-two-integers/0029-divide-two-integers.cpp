class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        bool sign = true;
        
        if(divisor < 0 && dividend >= 0) sign = false;
        else if(divisor > 0 && dividend <= 0) sign = false;
        long p = abs(dividend);
        long q = abs(divisor);
        long quotient = 0;
        while(p >= q) {
            int count = 0;
            
            while(p >= (q << (count+1)))
                count++;
            quotient += (1 << count); 
            p -= (q << count);
        }
        // cout<<(1 << 31) ;
        if(quotient == INT_MIN && sign)
            return INT_MAX;
        if(quotient == INT_MIN && !sign)
            return INT_MIN;

        return sign? quotient : -quotient;
    }
};