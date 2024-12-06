class Node:
    def __init__(self):
        self.list = [None]*26
        self.w = ""


def insert(node,s):
    for it in s:
        x = ord(it) - ord('a')
        if not node.list[x]:
            node.list[x] = Node()
        node = node.list[x]
    node.w = s

def search(i , j , node , ans , v):
    c = v[i][j]
    x = ord(c) - ord('a')
    if(c == '#' or not node.list[x]):
        return

    node = node.list[x]
    v[i][j] = '#'
    if node.w:
        ans.append(node.w)
        node.w = ""

    d = [(1,0),(-1,0),(0,1),(0,-1)]
    for d1,d2 in d:
        ni = i + d1
        nj = j + d2
        if ni>=0 and ni<len(v) and nj>=0 and nj<len(v[0]):
            search(ni,nj,node,ans,v)

    v[i][j] = c 


class Solution:
    def findWords(self, v: List[List[str]], w: List[str]) -> List[str]:
        root = Node()
        for it in w:
            insert(root , it)
        ans = []

        for i in range(0,len(v)):
            for j in range(0,len(v[0])):
                search(i,j,root,ans,v)

        return ans

        