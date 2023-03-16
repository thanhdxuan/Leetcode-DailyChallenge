class Solution {
public:
    int compress(vector<char>& chars) {
      vector<char> nums;
      for(int i = 0; i < chars.size(); i++) {
        nums.push_back(chars[i]);
        int count = 1;
        for(int j = i + 1; j < chars.size(); j++) {
          if (chars[j] != chars[i]) {
            if (count < 10 && count > 1) {
              nums.push_back(count + '0');
            }
            else if (count >= 10) {
              string temp = std::to_string(count);
              for (auto x: temp) {
                nums.push_back(x);
              }
            }
            i = j - 1;
            break;
          }
          count++;
          if (j == chars.size() - 1) {
            if (count < 10 && count > 1) {
              nums.push_back(count + '0');
            }
            else if (count >= 10) {
              string temp = std::to_string(count);
              for (auto x: temp) {
                nums.push_back(x);
              }
            }
            i = j;
          }
        }
      }
      chars = nums;
      return nums.size();
    }
};
