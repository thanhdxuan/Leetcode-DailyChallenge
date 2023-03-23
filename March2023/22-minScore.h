// Problem: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

// This my solution using breadth first search
class Solution {
public:
    int bfs(int& n, vector<vector<pair<int, int>>>& adj) {
        vector<bool> visit(n + 1);
        queue<int> q;
        int answer = numeric_limits<int>::max();

        q.push(1);
        visit[1] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& edge : adj[node]) {
                answer = min(answer, edge.second);
                if (!visit[edge.first]) {
                    visit[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        return answer;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        return bfs(n, adj);
    }
};
class Other: public Solution {
  public:
    void dfs(int& n, vector<vector<pair<int, int>>>& adjs, vector<bool>& visited, int& ans) {
        visited[n] = true;
        auto adj_arr = adjs[n];
        for (auto adj : adj_arr) {
            if (!visited[adj.first]) {
                cout << adj.first << " " << adj.second << " " << ans << endl;
                dfs(adj.first, adjs, visited, ans);
            }
            ans = min(ans, adj.second);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<bool> visited(n, false);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
            //(neighbor, weight)
        }
        int ans = INT_MAX;
        int k = 1;
        dfs(k, adj, visited, ans);
        return ans;
    }
};
