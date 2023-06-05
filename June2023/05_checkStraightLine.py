class Solution:
    def checkStraightLine(self, cdn: List[List[int]]) -> bool:
        q = [cdn[1][0] - cdn[0][0], cdn[1][1] - cdn[0][1]]
        for c_x, c_y in cdn:
            if q[0] == 0:
                if c_x != cdn[0][0]: return False
            elif q[1] == 0:
                if c_y != cdn[0][1]: return False
            else:
                _nqx = (c_x - cdn[0][0]) / q[0]
                _nqy = (c_y - cdn[0][1]) / q[1]
                if _nqx != _nqy: return False
        return True
