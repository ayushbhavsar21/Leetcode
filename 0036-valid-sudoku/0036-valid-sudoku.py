class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        columns = [[0] * 9 for _ in range(9)]
        rows = [[0] * 9 for _ in range(9)]
        blocks = [[[0] * 9 for _ in range(3)] for _ in range(3)]
        
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    continue
                currVal = int(board[r][c]) - 1 
                
                if columns[currVal][c] or rows[r][currVal] or blocks[r // 3][c // 3][currVal]:
                    return False
                
                columns[currVal][c] += 1
                rows[r][currVal] += 1
                blocks[r // 3][c // 3][currVal] += 1
        
        return True
