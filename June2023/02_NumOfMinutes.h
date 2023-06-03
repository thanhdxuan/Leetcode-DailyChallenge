/* Problem: https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
 */
class Solution {
public:
    int dfs(int headID, vector<vector<int>> &adjs, vector<int> &informTime) {
        if (adjs[headID].size() == 0) {
          return 0;
        }
        int _max = 0;
        for (auto adj : adjs[headID]) {
          int temp = dfs(adj, adjs, informTime);
          _max = max(temp, _max);
        }
        return informTime[headID] + _max;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjs(n);
        // n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
        for (int i = 0; i < n; i++) {
            if (i != headID) adjs[manager[i]].push_back(i);
        }
        int min = dfs(headID, adjs, informTime); //Find maximum of time
        return min;
    }
};
