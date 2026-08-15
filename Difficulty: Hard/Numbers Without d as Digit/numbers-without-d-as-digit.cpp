class Solution {
  public:
      int dp[12][2][2];
      string s;
      int target_d;

      int countValid(int idx, bool tight, bool started) {
          if (idx == s.size()) {
              return started ? 1 : 0;
          }

          if (dp[idx][tight][started] != -1) {
              return dp[idx][tight][started];
          }

          int limit = tight ? (s[idx] - '0') : 9;
          int ans = 0;

          for (int dig = 0; dig <= limit; dig++) {
              if (!started && dig == 0) {
                  // Leading zeros do not count as digit '0'
                  ans += countValid(idx + 1, tight && (dig == limit), false);
              } else {
                  // Skip if the current digit equals d
                  if (dig == target_d) continue;
                  ans += countValid(idx + 1, tight && (dig == limit), true);
              }
          }

          return dp[idx][tight][started] = ans;
      }

      int countWithout(int n, int d) {
          if (n <= 0) return 0;

          s = to_string(n);
          target_d = d;
          memset(dp, -1, sizeof(dp));

          return countValid(0, true, false);
      }
  };