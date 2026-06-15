class Solution {
public:
    int minimumCost(vector<int> &cost, int w) {
        int n = cost.size();
        // Initialize DP array with a large value representing infinity
        vector<int> dp(w + 1, 1e9); 
        
        // Base case: 0 cost to fill 0 weight
        dp[0] = 0; 

        // Iterate through all weights from 1 to w
        for (int i = 1; i <= w; i++) {
            // Try every packet size (1 kg up to n kg)
            for (int j = 1; j <= n; j++) {
                // Check if the packet is available and fits in the current weight 'i'
                if (j <= i && cost[j - 1] != -1) {
                    // Only update if the previous subproblem (i - j) is reachable
                    if (dp[i - j] != 1e9) {
                        dp[i] = min(dp[i], cost[j - 1] + dp[i - j]);
                    }
                }
            }
        }

        // If dp[w] is still infinity, it means exact weight w cannot be formed
        return (dp[w] == 1e9) ? -1 : dp[w];
    }
};