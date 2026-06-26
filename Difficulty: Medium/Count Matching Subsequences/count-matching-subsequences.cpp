class Solution {
  public:
    int countWays(string &s1, string &s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        int MOD = 1e9 + 7;
        
        // dp[j] stores the number of times prefix s2[0...j-1] appears as a subsequence
        vector<int> dp(m + 1, 0);
        
        // Base case: An empty s2 has 1 matching subsequence in any prefix of s1
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            // Traverse backwards to use values from the previous iteration of row i-1
            for (int j = m; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
                }
                // If they don't match, dp[j] remains unchanged (dp[i][j] = dp[i-1][j])
            }
        }
        
        return dp[m];
    }
};
