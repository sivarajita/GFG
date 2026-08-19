class Solution {
  private:
      int countTripletsLessThanOrEqual(std::vector<int>& arr, int val) {
          int n = arr.size();
          int count = 0;

          for (int i = 0; i < n - 2; i++) {
              int left = i + 1;
              int right = n - 1;

              while (left < right) {
                  int sum = arr[i] + arr[left] + arr[right];
                  if (sum <= val) {
                      // Since arr is sorted, all elements between left and right 
                      // paired with arr[i] and arr[left] will also have sum <= val
                      count += (right - left);
                      left++;
                  } else {
                      right--;
                  }
              }
          }
          return count;
      }

  public:
      int countTriplets(std::vector<int>& arr, int l, int r) {
          std::sort(arr.begin(), arr.end());
          return countTripletsLessThanOrEqual(arr, r) - countTripletsLessThanOrEqual(arr, l - 1);
    }
};