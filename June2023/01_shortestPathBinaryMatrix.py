# Problem: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
class Solution:
    def isBound(self, x, y, n):
        return x >= 0 and x <= n - 1 and y >= 0 and y <= n - 1
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] == 1 or grid[n - 1][n - 1] == 1:
            return -1
        
        dirs = [(1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1)] # 8 - directions
        queue = []
        queue.append((0, 0))
        grid[0][0] = 1
        while len(queue) > 0:
            _x, _y = queue.pop(0)
            if _x == n - 1 and _y == n - 1:
                return grid[_x][_y]
            for _newx, _newy in dirs: # move to each directions
                _newposx = _x + _newx
                _newposy = _y + _newy
                if self.isBound(_newposx, _newposy, n) and grid[_newposx][_newposy] == 0:
                    queue.append((_newposx, _newposy)) # append suitable position to queue
                    grid[_newposx][_newposy] = grid[_x][_y] + 1
        return -1
