class Solution:
    def solve(self , i , v , c , t , ans ):
        if i >= len(c):
            if(t == 0):
                ans.append(v[:])
            return 
        
        if c[i] <= t:
            v.append(c[i])
            self.solve(i , v , c , t - c[i] , ans)
            v.pop()
        self.solve(i + 1, v , c , t , ans)


    def combinationSum(self, c: List[int], t: int) -> List[List[int]]:
        ans = [] 
        v = []
        self.solve(0 , v , c , t , ans)

        return ans
