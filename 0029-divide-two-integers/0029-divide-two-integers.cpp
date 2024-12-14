class Solution {
public:
    int divide(int d1, int d2) {
        bool s = 1;
        if((d1>=0 && d2<0) || (d1<=0 && d2>0))
            s = 0;

        long p = abs(long(d1));
        long d = abs(long(d2));
        long q = 0;

        while(p >= d){
            int c = 0;

            while(p >= (d << (c + 1))){
                c++;
            }
            q += (1 << c);

            p -= (d << c);
        }
        if(q == (1<<31) && s)
            return INT_MAX;
        if(q == (1<<31) && !s)
            return INT_MIN;

        return s ? q : -q;
    }
};