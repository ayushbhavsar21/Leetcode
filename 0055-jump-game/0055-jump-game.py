class Solution:
    def canJump(self, nums: List[int]) -> bool:
        next = 0
        curr = 0
        n = len(nums)

        for i in range(0 , n):
            next = max(next  , i + nums[i])

            if(i > curr):
                return False
            if(curr == i):
                curr = next

        return True

        
