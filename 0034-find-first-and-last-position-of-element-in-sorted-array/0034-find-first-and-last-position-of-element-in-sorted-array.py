class Solution:
    def solve(self, nums: List[int],ans: List[int],mid: int) -> None :
        l = mid
        r = mid
        while l >= 0 and nums[l] == nums[mid] :
            l -= 1

        ans[0] = l + 1
        while r < len(nums) and nums[r] == nums[mid]:
            r += 1
        ans[1] = r - 1

    def searchRange(self, nums: List[int], t: int) -> List[int]:
        n = len(nums)
        if(n == 0 or nums[n-1] < t):
            return [-1,-1]
        s = 0
        e = n-1
        mid = s + (e - s)//2
        ans = [-1,-1]
        while(s <= e):
            mid = s + (e - s)//2
            if nums[mid] == t :
                self.solve(nums , ans , mid)
                return ans

            elif nums[mid] > t:
                e = mid - 1
            else:
                s = mid + 1

        return ans