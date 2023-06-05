//Problem: https://leetcode.com/problems/check-if-it-is-a-straight-line/description/
class Solution {
public:
    int getYDiff(vector<int> &a, vector<int> &b) {
        return a[1] - b[1];
    }
    int getXDiff(vector<int> &a, vector<int> &b) {
        return a[0] - b[0];
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //Slop = deltaY / deltaX
        int deltaX0 = getXDiff(coordinates[1], coordinates[0]);
        int deltaY0 = getYDiff(coordinates[1], coordinates[0]);

        for (int i = 2; i < coordinates.size(); i++) {
            if (deltaY0 * getXDiff(coordinates[i], coordinates[0]) != deltaX0 * getYDiff(coordinates[i], coordinates[0])) {
                return false;
            }
        }
        return true;
    }
};
