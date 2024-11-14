class Solution:
    def grayCode(self, n: int) -> List[int]:
        v = []
        x  = 1 << n
        for i in range(0 , x):
            v.append(i ^ (i >> 1))
        return v