class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n == 1) return arr[0];

        int count_neg = 0;
        int count_zero = 0;
        int max_neg = INT_MIN;
        int min_pos = INT_MAX;
        int prod = 1;

        for (int num : arr) {
            if (num == 0) {
                count_zero++;
                continue;
            }
            if (num < 0) {
                count_neg++;
                max_neg = max(max_neg, num);
            } else {
                min_pos = min(min_pos, num);
            }
            prod *= num;
        }

        // Case 1: No negative numbers
        if (count_neg == 0) {
            if (count_zero > 0) return 0;
            return min_pos;
        }

        // Case 2: Even count of negatives
        if (count_neg % 2 == 0) {
            prod /= max_neg;
        }

        return prod;
    }
};