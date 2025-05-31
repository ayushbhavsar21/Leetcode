class Solution:
    def search(self, nums: List[int], t: int) -> bool:
        n = len(nums)
        s = 0
        e = n-1
        mid = s - (s - e)//2

        while(s <= e):
            mid = s - (s - e)//2
            if(nums[mid] == t):
                return True
            if(nums[s] == nums[mid] and nums[mid] == nums[e]):
                s= s+1
                e= e-1

            elif(nums[s] <= nums[mid]):
                if(nums[s] <= t and nums[mid] > t):
                    e = mid-1
                else:
                    s = mid+1
            else:
                if(nums[mid] < t and nums[e]>= t):
                    s = mid+1
                else:
                    e = mid - 1

        return False