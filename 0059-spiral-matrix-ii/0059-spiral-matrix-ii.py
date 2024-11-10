class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        v = [ [0 for _ in range(n)] for _ in range(n)]
        top = 0 
        bottom = n -1
        left = 0
        right = n-1
        c = 1

        while(top <= bottom and left <= right):

            for i in range(left , right+1):
                v[top][i] = c
                c+= 1
            top += 1

            for i in range(top , bottom +1):
                v[i][right] = c
                c+= 1
            right -= 1

            for i in range(right , left-1 , -1):
                v[bottom][i] = c
                c+= 1
            bottom -= 1

            for i in range(bottom , top-1 , -1):
                v[i][left] = c
                c+= 1
            left += 1
        
        return v