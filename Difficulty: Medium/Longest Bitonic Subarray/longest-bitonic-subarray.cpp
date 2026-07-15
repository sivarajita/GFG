class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        vector<int> inc(n, 1);
        vector<int> dec(n, 1);
        
        // Construct the increasing array (left to right)
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }
        
        // Construct the decreasing array (right to left)
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }
        
        // Find the maximum length of the bitonic subarray
        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            int currentBitonicLength = inc[i] + dec[i] - 1;
            if (currentBitonicLength > maxLength) {
                maxLength = currentBitonicLength;
            }
        }
        
        return maxLength;
    }
};