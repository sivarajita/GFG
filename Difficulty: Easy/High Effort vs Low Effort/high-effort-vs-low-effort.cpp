class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n = h.size();
        if (n == 0) return 0;
        if (n == 1) return max(h[0], l[0]);

        int prev2 = 0;
        int prev1 = max(h[0], l[0]);

        for (int i = 1; i < n; i++) {
            int current = max(h[i] + prev2, l[i] + prev1);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};