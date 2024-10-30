class Solution:
    def solve(self , i , v , c , t , ans ):
        if i >= len(c):
            if(t == 0):
                ans.append(v[:])
            return 
        
        if c[i] <= t:
            v.append(c[i])
            self.solve(i+1 , v , c , t - c[i] , ans)
            v.pop()
        j = i + 1
        while j < len(c) and c[j] == c[i]:
            j += 1
        self.solve(j, v, c, t, ans)


    def combinationSum2(self, c: List[int], t: int) -> List[List[int]]:
        ans = [] 
        v = []
        c.sort()
        self.solve(0 , v , c , t , ans)
        return ans
