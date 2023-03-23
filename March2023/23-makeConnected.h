//Problem: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
//This is my Solution using breadth first search
class Solution {
public:
    void bfs (int n, vector<vector<int>>& adjs, vector<bool> & visited) {
        queue<int> nums;
        nums.push(n);
        visited[n] = true;
        while(!nums.empty()) {
            int curr = nums.front();
            nums.pop();
            vector<int> adj = adjs[curr];
            for (int i = 0; i < adj.size(); i++) {
                if (!visited[adj[i]]) {
                    nums.push(adj[i]);
                    visited[adj[i]] = true;
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjs(n);
        int numsofedges = connections.size();
        for (auto edge : connections) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i, adjs, visited);
                ans++;
            }
        }

        return (numsofedges < n - 1) ? (-1) : (ans - 1);
    }
};
