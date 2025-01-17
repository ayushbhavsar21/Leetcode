class Solution:
    def compareVersion(self, s1: str, s2: str) -> int:
        
        l1 = s1.split('.')
        l2 = s2.split('.')

        
        n = max(len(l1), len(l2))
        
        
        for i in range(len(l1), n):
            l1.append('0')
        for i in range(len(l2), n):
            l2.append('0')

        
        for i in range(n):
            
            num1 = int(l1[i])
            num2 = int(l2[i])
            if num1 > num2:
                return 1
            elif num2 > num1:
                return -1

       
        return 0
