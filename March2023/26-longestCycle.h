//Problem: https://leetcode.com/problems/longest-cycle-in-a-graph/description/
//
class Solution {
public:
    void dfs(int &curr, vector<bool> &visited, vector<int> &edges, int &ans, unordered_map<int, int> &dist) {
        visited[curr] = true;
        int neighbor = edges[curr];
        if (neighbor != -1 && !visited[neighbor]) {
            dist[neighbor] = dist[curr] + 1;
            dfs(neighbor, visited, edges, ans, dist);
        }
        else if (neighbor != -1 && visited[neighbor]) {
            if (dist[neighbor]) {
                ans = max(ans, dist[curr] - dist[neighbor] + 1);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_map<int, int> dist;
                dist[i] = 0;
                dfs(i, visited, edges, ans, dist);
            }
        }
        return ans;
    }
};
