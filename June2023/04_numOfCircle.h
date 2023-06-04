//Problem: https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    void dfs(int n, vector<vector<int>> &adjs, vector<bool> &visited) {
        visited[n] = true;
        if (adjs[n]. size() == 0) {
            return;
        }
        for (int i = 0; i < adjs[n].size(); i++) {
            if (!visited[adjs[n][i]]) {
                dfs(adjs[n][i], adjs, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjs(n);
        for (int i = 0; i < n; i++) {
            printf("List %d: ", i);
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] && i != j) {
                    adjs[i].push_back(j);
                    printf("%d ", j);
                }
            }
            cout << "\n";
        }
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res++;
                dfs(i, adjs, visited);
            }
        }
        return res;
    }
};
