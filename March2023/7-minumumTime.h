class Solution {
  public:
   long long minimumTime(vector<int>& time, int totalTrips) {
      long long l = 1;
      long long r = 1LL * *max_element(time.begin(), time.end()) * totalTrips;
      while (l < r) {
         long long mid = (l + r) / 2;
         long long trip = numsTrip(time, mid);
         if (trip < totalTrips) {
            l = mid + 1;
         }
         else {
            r = mid;
         }
      }
      return l;
   }
   long long numsTrip(vector<int> &time, long long t) { //nums of trip for time = t
      //numstrip of i.th bus: t / time[i]
      long long n = time.size();
      long long numstrip = 0;
      for (long long i = 0; i < n; i++) {
         numstrip += (t / time[i]);
      }
      return numstrip;
   }
};
