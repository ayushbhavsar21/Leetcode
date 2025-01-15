class Solution:
    def reverseWords(self, s: str) -> str:
        v = s.split()
        v.reverse()
        # print(v)
        s = ' '.join(v)
        return s
    
        