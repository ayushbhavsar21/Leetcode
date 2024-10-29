class Solution:
    def countAndSay(self, n: int) -> str:
        s = "1"
        if (n == 0 ):
           return s

        n -= 1
        while n > 0:
            i =0 
            freq = 0
            pre = '0'
            t = ""
            while i<len(s):
                if i == 0:
                    pre = s[i]
                    freq += 1
                else:
                    if pre == s[i]:
                        freq += 1
                    else:
                        t += str(freq)
                        t += pre

                        pre = s[i]
                        freq = 1
                
                i += 1
            t += str(freq)
            t += pre
            s = t
            n -= 1

        return s