class Solution:
    def dfs(self, i , adj , ans) -> int:
        s = 1
        for it in adj[i]:
            s += self.dfs(it , adj , ans)

        ans[i] = s
        return s

    def findSubtreeSizes(self, p: List[int], s: str) -> List[int]:
        p2 = p[:]
        n = len(p)
        for i in range(1,n):
            y = p[i]
            while (y != -1 and s[y] != s[i]):
                y = p[y]
            if y != -1:
                p2[i] = y

        adj = [[] for _ in range(n)]

        for i in range(1,n):
            adj[p2[i]].append(i)
        ans = [0 for _ in range (n)]
        self.dfs(0 , adj , ans)

        return ans

