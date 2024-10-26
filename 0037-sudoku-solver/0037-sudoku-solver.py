class Solution:
    def __init__(self):
        self.col = [[0 for _ in range(9)] for _ in range(9)]
        self.row = [[0 for _ in range(9)] for _ in range(9)]
        self.box = [[[0 for _ in range(9)] for _ in range(3)] for _ in range(3)]

    def solve(self, i, j, s) -> bool:
        if i == 9:
            return True
        if j == 9:
            return self.solve(i + 1, 0, s)
        if s[i][j] != ".":
            return self.solve(i, j + 1, s)

        for num in range(9):
            if not self.row[i][num] and not self.col[j][num] and not self.box[i // 3][j // 3][num]:
                s[i][j] = str(num + 1)
                self.row[i][num] = 1
                self.col[j][num] = 1
                self.box[i // 3][j // 3][num] = 1

                if self.solve(i, j + 1, s):
                    return True

                
                s[i][j] = '.'
                self.row[i][num] = 0
                self.col[j][num] = 0
                self.box[i // 3][j // 3][num] = 0

        return False

    def solveSudoku(self, s: List[List[str]]) -> None:
        for i in range(9):
            for j in range(9):
                if s[i][j] != ".":
                    x = int(s[i][j]) - 1
                    self.row[i][x] = 1
                    self.col[j][x] = 1
                    self.box[i // 3][j // 3][x] = 1

        self.solve(0, 0, s)
