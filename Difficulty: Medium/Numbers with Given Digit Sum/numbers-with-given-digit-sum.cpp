class Solution {
private:
    // Helper function to calculate combinations for the remaining digits
    int solve(int digits, int current_sum, std::vector<std::vector<int>>& dp) {
        // Base Cases
        if (current_sum < 0) return 0; 
        if (digits == 0) {
            return (current_sum == 0) ? 1 : 0; 
        }
        
        // Return memoized result if we've already computed this state
        if (dp[digits][current_sum] != -1) return dp[digits][current_sum];
        
        int ways = 0;
        // For all subsequent digits, we can use 0 through 9
        for (int i = 0; i <= 9; i++) {
            ways += solve(digits - 1, current_sum - i, dp);
        }
        
        // Store and return the result
        return dp[digits][current_sum] = ways;
    }

public:
    int countWays(int n, int sum) {
        // Impossible cases: Min sum is 1 (e.g., 100..), Max sum is 9*n (e.g., 999..)
        if (sum < 1 || sum > 9 * n) return -1;
        
        // Initialize a 2D DP array with -1
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(sum + 1, -1));
        
        int total_ways = 0;
        
        // The first digit cannot be 0, so we strictly loop from 1 to 9
        for (int i = 1; i <= 9; i++) {
            if (sum - i >= 0) {
                total_ways += solve(n - 1, sum - i, dp);
            }
        }
        
        // The problem expects -1 if no such numbers can be formed
        return total_ways > 0 ? total_ways : -1;
    }
};