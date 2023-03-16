class Solution {
public:
    int minJumps(vector<int>& arr) {
      long long n = arr.size();
      vector<long long> steps(n, 0);
      int root = 0;
      queue<long long> nums;
      nums.push(root); //0
      unordered_map<long long, vector<long long>> sameVal;
      for (int i = 0; i < n; i++) sameVal[arr[i]].push_back(i);
      while (!nums.empty()) {
        long long curr = nums.front(); //0
        nums.pop(); //[]
        if (curr - 1 >= 0) {
          if (steps[curr - 1] == 0) {
            steps[curr - 1] = steps[curr] + 1;
            if (curr - 1 == n - 1) {
              //last index
              return steps[curr - 1];
            }
            nums.push(curr - 1);
          }
        }
        if (curr + 1 < n) {
          if (steps[curr + 1] == 0) {
            steps[curr + 1] = steps[curr] + 1;
            if (curr + 1 == n - 1) {
              //last index
              return steps[curr + 1];
            }
            nums.push(curr + 1);
          }
        }
        for (long long i: sameVal[arr[curr]]) {
          if (i != curr) {
            if (steps[i] == 0) {
              steps[i] = steps[curr] + 1;
              nums.push(i);
            }
            if (i == n - 1) return steps[i];
          }
        }
        sameVal[arr[curr]].clear();
      }
      return 0;
      
    }
};

/*
arr = [100,-23,-23,404,100,23,23,23,3,404]

q: 0
q: 1, 4
q: 4, 2
q: 2, 3, 5
q: 3, 5
q: 5, 9
visited: 0, 1, 4, 2, 3
*/
