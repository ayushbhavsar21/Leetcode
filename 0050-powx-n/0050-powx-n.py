class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1

        if n == 0:
            return 1   

        elif n < 0:     
            x = 1/x
            n = abs(n)

        while n > 0:            
            if n&1:              
                res = res*x      
            x = x*x             
            n = n>>1

        return res