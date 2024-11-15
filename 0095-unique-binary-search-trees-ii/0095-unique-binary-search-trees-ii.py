class Solution:
    def __init__(self):
        self.dp = {}

    def buildTree(self, start, end):
        if start > end:
            return [None]
        
        # Check if the result for the range [start, end] is already computed
        if (start, end) in self.dp:
            return self.dp[(start, end)]

        ans = []
        for i in range(start, end + 1):
            # Recursively generate all possible left and right subtrees
            leftSubTree = self.buildTree(start, i - 1)
            rightSubTree = self.buildTree(i + 1, end)
            
            # Combine left and right subtrees with the current root
            for left in leftSubTree:
                for right in rightSubTree:
                    root = TreeNode(i)
                    root.left = left
                    root.right = right
                    ans.append(root)
        
        # Cache the result for the range [start, end]
        self.dp[(start, end)] = ans
        return ans

    def generateTrees(self, n):
        if n == 0:
            return []
        return self.buildTree(1, n)
