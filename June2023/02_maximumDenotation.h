/*Problem: https://leetcode.com/problems/detonate-the-maximum-bomb*/
class Solution {
public:
    int MaxBomb = 1;
    int bfs(int n, vector<bool> &visited, unordered_map<int, vector<int>> &adj) {
        visited[n] = true;
        cout << "BFS: " << n << '\n';
        queue<int> mq;
        mq.push(n);
        int count = 0;
        vector <bool> mm (visited.size(), false);
        while (!mq.empty()) {
            count++;
            int curr = mq.front();
            mq.pop();
            cout << "pop: " << curr << '\n';
            for (auto &adjs : adj[curr]) {
                if (!visited[adjs]) {
                    mq.push(adjs);
                    cout << "push: " << adjs << "\n";
                    visited[adjs] = true;
                }
            }
        }
        cout << "count: " << count << "\n";
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> mymap;
        for(int i = 0; i < n; i++) {
            cout << i << ": ";
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    long long x = bombs[i][0] - bombs[j][0];
                    long long y = bombs[i][1] - bombs[j][1];
                    double dis = sqrtl(x * x + y * y);
                    if (dis <= bombs[i][2]) {
                        cout << j << " ";
                        mymap[i].push_back(j);
                    }
                }
            }
            cout << "\n";
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            // if (!visited[i]) {
                vector<bool> visited(n, false);
                int temp = bfs(i, visited, mymap);
                res = max(res, temp);
            // }
        }
        return res;
    }
};
