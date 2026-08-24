class Solution {
  public:
    int prefixStrings(int n) {
        // code here
        long long MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = (dp[i] + (dp[j] * dp[i - 1 - j]) % MOD) % MOD;
            }
        }

        return dp[n];
    }
};