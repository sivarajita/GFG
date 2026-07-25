class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n = mat.size();
        
        // Build 1-based (n+1) x (n+1) prefix sum array
        vector<std::vector<int>> pref(n + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                pref[i][j] = mat[i - 1][j - 1] 
                           + pref[i - 1][j] 
                           + pref[i][j - 1] 
                           - pref[i - 1][j - 1];
            }
        }
        
        int max_sum = INT_MIN;
        
        // Iterate through all possible bottom-right corners (i, j) of a k x k sub-matrix
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= n; ++j) {
                int current_sum = pref[i][j] 
                                - pref[i - k][j] 
                                - pref[i][j - k] 
                                + pref[i - k][j - k];
                                
                max_sum = max(max_sum, current_sum);
            }
        }
        
        return max_sum;
    }
};