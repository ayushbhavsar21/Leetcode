class Solution:
    def solve(self,nums , ans , v , st):
        if(len(nums) == len(v)):
            ans.append(v[:])

        for i in range(0 , len(nums)):
            if i not in st:
                st.add(i)
                v.append(nums[i])
                self.solve(nums , ans ,v , st)
                st.remove(i)
                v.pop()


    def permute(self, nums: List[int]) -> List[List[int]]:
        st = set()
        v = []
        ans = []

        self.solve(nums , ans , v, st)

        return ans