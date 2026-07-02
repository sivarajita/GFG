class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        vector<bool> dp(k, false);

        for (int num : arr) {
            // Take remainder of the current element
            int rem = num % k;
            
            // If the element itself is divisible by k, we found a valid subset
            if (rem == 0) return true;

            // To avoid using the current element multiple times, 
            // create a temporary array to store updates for this iteration
            vector<bool> next_dp = dp;

            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    int new_rem = (r + rem) % k;
                    if (new_rem == 0) return true; // Found a subset divisible by k
                    next_dp[new_rem] = true;
                }
            }

            // The current element itself can start a new subset remainder
            next_dp[rem] = true;
            dp = next_dp;
        }

        return dp[0];
    }
};