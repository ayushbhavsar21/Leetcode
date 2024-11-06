class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        next = 0
        curr = 0
        ans = 0

        for i in range(0,n-1):
            next = max(next , i + nums[i])

            if curr == i:
                ans += 1
                curr = next

        return ans