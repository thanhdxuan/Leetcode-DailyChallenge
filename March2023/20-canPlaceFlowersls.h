class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < (int)flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                //Check if left plots empty
                bool isEmptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                //Check if right plots empty
                bool isEmptyRight = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0) ;
                if (isEmptyLeft && isEmptyRight) {
                    n = n - 1;
                    flowerbed[i] = 1;
                }
            }
            if (n <= 0) return true;
        }
        return false;
    }
};
