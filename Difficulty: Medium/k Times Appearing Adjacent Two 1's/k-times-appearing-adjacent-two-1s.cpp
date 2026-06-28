class Solution {
  public:
    int countStrings(int n, int k) {
        // code here
        if (k >= n) return 0; // Impossible to have k pairs in a string of length n if k >= n
        
        long long MOD = 1e9 + 7;
        
        // dp[j][last] stores counts for the current length
        // We use a 3D-like transition but optimized to 2D by tracking the previous length's states
        vector<vector<long long>> prev(k + 1, vector<long long>(2, 0));
        
        // Base cases for length 1
        prev[0][0] = 1; // "0"
        prev[0][1] = 1; // "1"
        
        for (int i = 2; i <= n; i++) {
            vector<vector<long long>> curr(k + 1, vector<long long>(2, 0));
            for (int j = 0; j <= k; j++) {
                // Ending with 0
                curr[j][0] = (prev[j][0] + prev[j][1]) % MOD;
                
                // Ending with 1
                curr[j][1] = prev[j][0]; // coming from an ending '0', pairs don't increase
                if (j > 0) {
                    curr[j][1] = (curr[j][1] + prev[j - 1][1]) % MOD; // coming from an ending '1', pairs increase
                }
            }
            prev = curr; // Move to the next length
        }
        
        return (prev[k][0] + prev[k][1]) % MOD;
    
    }
};