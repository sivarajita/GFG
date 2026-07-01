class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n == 1) return arr[0];

        // max_no_deletion[i] stores the max subarray sum ending at i with 0 deletions
        vector<int> max_no_deletion(n);
        // max_one_deletion[i] stores the max subarray sum ending at i with 1 deletion
        vector<int> max_one_deletion(n);

        // Base cases for the first element
        max_no_deletion[0] = arr[0];
        max_one_deletion[0] = arr[0]; // If we only have 1 element, we can't delete it (subarray must be non-empty)

        int overall_max = arr[0];

        for (int i = 1; i < n; i++) {
            // Standard Kadane's choice: start a new subarray at i, or continue the previous one
            max_no_deletion[i] = max(arr[i], max_no_deletion[i - 1] + arr[i]);

            // Two cases for 1 deletion:
            // 1. Keep arr[i] but add it to a previous subarray that already skipped an element
            // 2. Skip arr[i], which means we take the previous subarray sum that had 0 deletions
            max_one_deletion[i] = max(max_one_deletion[i - 1] + arr[i], max_no_deletion[i - 1]);

            // Track the maximum sum encountered so far
            overall_max = max({overall_max, max_no_deletion[i], max_one_deletion[i]});
        }

        return overall_max;
    }
};