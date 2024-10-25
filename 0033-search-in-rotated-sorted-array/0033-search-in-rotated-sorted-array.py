class Solution:
    def search(self, nums: List[int], t: int) -> int:
        n = len(nums)
        s = 0 
        e = n-1 
        mid = s + (e - s)//2 

        while s<= e:
            mid = s + (e - s)//2 
            if(nums[mid] == t):
                return mid

            elif(nums[mid] >= nums[s]):
                if(nums[s] <= t and nums[mid] > t):
                    e = mid - 1
                else :
                    s = mid + 1
            else:
                if(nums[mid] < t and nums[e] >= t):
                    s = mid + 1
                else:
                    e = mid - 1

        return -1
