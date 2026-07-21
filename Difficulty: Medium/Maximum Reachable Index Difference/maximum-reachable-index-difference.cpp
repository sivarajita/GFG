class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n = s.size();

        vector<int> dp(n);

        // best[c] = maximum reachable ending index from any occurrence
        // of character ('a' + c) seen to the right.
        vector<int> best(26, -1);

        int ans = -1;

        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            dp[i] = i;

            if (c < 25 && best[c + 1] != -1)
                dp[i] = best[c + 1];

            best[c] = max(best[c], dp[i]);

            if (c == 0)
                ans = max(ans, dp[i] - i);
        }

        return ans;
    }
};