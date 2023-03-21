class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;
            }
            bool isEnd = (nums[i] != 0 && count != 0) || i == (n - 1);
            if (isEnd) {
                sum += (count * (count + 1)) / 2;
                count = 0;
            }
        }
        return sum;
    }
};
