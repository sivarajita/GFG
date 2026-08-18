class Solution {
  public:
    string compress(string &s) {
        // code here
        int n = s.length();
        if (n <= 1) return s;

        // Step 1: Compute KMP LPS array
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }
            if (s[i] == s[j]) j++;
            lps[i] = j;
        }

        // Step 2: Backward Greedy compression
        string res = "";
        int i = n - 1;
        while (i >= 0) {
            int len = i + 1;
            if (len % 2 == 0) {
                int k = len / 2;
                // Check if prefix of length k is a valid match
                int curr = lps[i];
                while (curr > k) {
                    curr = lps[curr - 1];
                }

                if (curr == k) {
                    res += '*';
                    i = k - 1;
                    continue;
                }
            }
            res += s[i];
            i--;
        }

        // Step 3: Reverse to get original left-to-right order
        reverse(res.begin(), res.end());
        return res;
    }
};
