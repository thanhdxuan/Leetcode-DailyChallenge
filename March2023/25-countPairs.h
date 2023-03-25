//Problem: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

class Solution {
public:
    void dfs(int &n, vector<vector<int>> &adjs, vector<bool> &visited, long long &num) {
        visited[n] = true;
        num++;
        for (auto &adj : adjs[n]) {
            if (!visited[adj]) {
                dfs(adj, adjs, visited, num);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited (n, false);
        long long ans = 0;
        long long num = 0; //Using to count nums of node of a connected component
        for (int i = 0; i < n; i++) {
            num = 0;
            if (!visited[i]) {
                dfs(i, adj, visited, num);
                ans += num * (n - num); // Count pairs of a connected component
            }
        }
        return ans / 2; //Repeatations
    }
};
