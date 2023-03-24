//Problem: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/submissions/921216786/
//This is solution using breadth first search
/*
 * Create an adjacent array of a undirected graph with pair (neighbor-node, direction-flags). In there, direction-flags is 1 if have a path from current node to neighbor-node, otherwise is 0
 * Then bfs start in 0, if this node have direction-flags is 1, then ans = ans + 1
 *
 *
 * 
 * */
class Solution {
public:
    void bfs(int n, vector<vector<pair<int,int>>> &adjs, vector<bool> &visited, int &ans) {
        visited[n] = true;
        queue<int> edges;
        edges.push(n);
        while (!edges.empty() ) {
            int curr = edges.front();
            edges.pop();
            for (auto &adj : adjs[curr]) {
                if (!visited[adj.first]) {
                    cout << curr << " " << adj.first << " " << adj.second << endl;
                    edges.push(adj.first);
                    visited[adj.first] = true;
                    if (adj.second == 1) ans++;
                }
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adjs(n);
        for (auto &i : connections) {
            //left->right : 1
            //right->left : 0
            adjs[i[0]].push_back(make_pair(i[1], 1));
            adjs[i[1]].push_back(make_pair(i[0], 0));
        }
        int k = 0;
        vector<bool> visited (n, false);
        int ans = 0;
        bfs(k, adjs, visited, ans);
        return ans;
    }
};
