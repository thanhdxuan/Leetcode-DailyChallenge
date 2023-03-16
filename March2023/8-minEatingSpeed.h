class Solution {
public:
   int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1;
        long long r = 1LL * *max_element(piles.begin(), piles.end());
        long long ans = 0;
        while (l < r) {
            long long mid = (l + r) / 2;
            long long hrs = hoursNeeded(piles, mid);
            if (hrs < h) {
               r = mid;
            }
            else if (hrs > h) {
               l = mid + 1;
            }
            else {
               ans = mid;
               r = mid;
            }
        }
        return ans == 0 ? l : ans;
    }
    long long hoursNeeded (vector<int> & piles, int k) {
        long long h = 0;
        for (auto i : piles) {
            if (i > k) {
                h += ceil((double)i / k);
            }
            else {
                h = h + 1;
            }
        }
        return h;
    }
};

/*
[30,11,23,4,20] - 8
30 - 19 = 11 2+1+2+1
2 + 1 + 1+ 1 + 1

len = 4
4 * 8 = 12
max = 11;
11 * 4  = 44;

*/
