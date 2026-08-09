class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        if (n == 1) return mat[0][0];

        // dp[j] will hold the max path sum ending at column j in current row
        vector<int> dp = mat[0];

        for (int i = 1; i < n; ++i) {
            // Find the top two max values and the index of the max value from previous row
            int max1 = -1, max2 = -1;
            int max1_idx = -1;

            for (int j = 0; j < n; ++j) {
                if (dp[j] > max1) {
                    max2 = max1;
                    max1 = dp[j];
                    max1_idx = j;
                } else if (dp[j] > max2) {
                    max2 = dp[j];
                }
            }

            // Compute DP for the current row
            vector<int> next_dp(n);
            for (int j = 0; j < n; ++j) {
                int best_prev = (j == max1_idx) ? max2 : max1;
                next_dp[j] = mat[i][j] + best_prev;
            }

            dp = next_dp;
        }

        // The answer is the maximum value in the last row DP
        int result = 0;
        for (int j = 0; j < n; ++j) {
            result = max(result, dp[j]);
        }

        return result;
    }
};