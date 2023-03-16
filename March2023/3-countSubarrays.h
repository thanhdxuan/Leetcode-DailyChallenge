
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int a = -1, b = -1, c = -1;
        long long count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
          if (nums[i] < minK || nums[i] > maxK) {
            //value out of range
            a = i;
          }
          if (nums[i] == minK) b = i;
          if (nums[i] == maxK) c = i;
          count += max(0, min(b,c) - a);
        }
        return count;

    }
};

//Queue: 1,3,5,2,7,5
/*
Tìm số valid subarray kết thúc tại i
valid subarray: cần chứa (minK, maxK) và không tồn tại elements ngoài[minK, maxK]
- Cần lưu index của các giá trị:
+ gần nhất ngoài đoạn [minK, maxK]
+ gần nhất maxK, minK

1,1,1,1
-1, -1, 
*/
