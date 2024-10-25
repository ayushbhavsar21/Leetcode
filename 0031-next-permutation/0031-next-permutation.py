class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        idx = -1

        for i in range(n-2 , -1 , -1):
            if nums[i] < nums[i+1]:
                idx = i
                break

        if idx == -1:
            nums.reverse()
            return
        
        nums[idx + 1:] = reversed(nums[idx + 1:])

        idx2 = -1
        for i in range(idx + 1 , n):
            if nums[i] > nums[idx]:
                idx2 = i
                break

        [nums[idx] , nums[idx2]] = [nums[idx2] , nums[idx]]

        return

        