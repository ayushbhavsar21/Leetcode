class Solution:
    def rotate(self, v: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(v)

        for j in range(n // 2):
            for i in range(j, n - 1 - j):
                
                (v[j][i], v[i][n - 1 - j], v[n - 1 - j][n - 1 - i], v[n - 1 - i][j]) = (
                    v[n - 1 - i][j], v[j][i], v[i][n - 1 - j], v[n - 1 - j][n - 1 - i])
        