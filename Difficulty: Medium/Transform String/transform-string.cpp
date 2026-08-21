class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        if (s1.length() != s2.length()) return -1;

        // 1. Verify character frequencies
        unordered_map<char, int> count;
        for (char c : s1) count[c]++;
        for (char c : s2) {
            count[c]--;
            if (count[c] < 0) return -1;
        }

        // 2. Greedy two-pointer from right to left
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int operations = 0;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                j--;
            } else {
                operations++;
            }
            i--;
        }

        return operations;
    }
};
