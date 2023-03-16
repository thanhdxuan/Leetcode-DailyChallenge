class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> nums;
        int start = 1;
        for (int i = 0; i < n; ) {
          if (arr[i] - start != 0) {
            for (int j = start; j < arr[i]; j++) {
              nums.push_back(j);
              if (nums.size() >= k) return nums[k - 1];
            }
            start = arr[i];
          }
          else {
            start++;
            i++;
          }
        }
        return arr[n - 1] - nums.size() + k;
    }
};

/*
start: 1 - 2 -> 1
start: 2 - 2
start: 3 - 3
start: 4 - 4
start: 5 - 7 - 5, 6
start: 6 - 7
start: 5 - 7 -> 5, 6
start: 7 - 11
*/
