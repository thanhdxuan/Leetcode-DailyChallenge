# Problem: https://leetcode.com/problems/number-of-provinces/description/
class Solution:
    def dfs(self, n: int, visited: List[bool], adjs: List[List[int]]):
        visited[n] = True
        if len(adjs[n]) == 0:
            return
        for i in range(len(adjs[n])):
            if not visited[adjs[n][i]]:
                self.dfs(adjs[n][i], visited, adjs)
        # return
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        adj = [[] for _ in range(n)]
        print(adj)
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1 and (i != j):
                    adj[i].append(j)
            print(f'List {i}: {adj[i]}')
        visited = [False] * n
        res = 0
        for i in range(n):
            if not visited[i]:
                res += 1
                self.dfs(i, visited, adj)
        return res
