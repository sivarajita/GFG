class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, 0);
        
        long long left_sum = 0;
        long long right_sum = 0;
        
        for (int i = 0; i < n; i++) {
            int mid = i / 2;
            
            // If i is even, the new element expands the right side or acts as a new median
            if (i % 2 == 0) {
                // For an odd number of elements, arr[mid] is the median.
                // Left half is from 0 to mid-1, Right half is from mid+1 to i.
                // We track rolling sums dynamically:
                left_sum += arr[mid]; 
                if (mid > 0) {
                    // Adjust because the previous middle element shifts out of the right side calculation
                    right_sum += arr[i] - arr[mid];
                }
                
                // Formula when elements are odd: 
                // Since left_sum currently includes arr[mid], we subtract it out conceptually
                // Ops = Right_Sum - (Left_Sum - arr[mid]) -> managed dynamically below
            } else {
                // For an even number of elements, halves are perfectly split at mid
                right_sum += arr[i];
            }
            
            // A much cleaner tracking with direct prefix tracking:
        }
        
        // Let's use a standard prefix sum array for crystal clear O(1) calculations
        vector<long long> pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }
        
        for(int i = 0; i < n; i++) {
            int mid = i / 2;
            long long current_ops = 0;
            
            if (i % 2 == 0) {
                // Odd number of elements: [0...mid-1], [mid], [mid+1...i]
                long long sum_left = pref[mid] - pref[0];
                long long sum_right = pref[i + 1] - pref[mid + 1];
                current_ops = sum_right - sum_left;
            } else {
                // Even number of elements: [0...mid], [mid+1...i]
                long long sum_left = pref[mid + 1] - pref[0];
                long long sum_right = pref[i + 1] - pref[mid + 1];
                current_ops = sum_right - sum_left;
            }
            ans[i] = current_ops;
        }
        
        return ans;
    }
};