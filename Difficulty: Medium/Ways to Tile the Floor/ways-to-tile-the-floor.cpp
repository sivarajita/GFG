class Solution {
  public:
    int countWays(int n, int m) {
        // code here.
        if (n < m) return 1;
        if (n == m) return 2;

        long long MOD = 1e9 + 7;
        
        // dp[i] will store the number of ways to tile a floor of size i x m
        vector<long long> dp(n + 1, 0);

        // Initialize base cases
        for (int i = 1; i < m; i++) {
            dp[i] = 1;
        }
        dp[m] = 2;

        // Fill the DP table using the recurrence relation
        for (int i = m + 1; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
        }

        return dp[n];
    }
};