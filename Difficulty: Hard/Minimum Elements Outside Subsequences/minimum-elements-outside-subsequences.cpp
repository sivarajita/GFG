class Solution {
    int memo[101][102][102];

        int solve(int i, int inc, int dec, const vector<int>& arr) {
            if (i == arr.size()) return 0;

            if (memo[i][inc][dec] != -1)
                return memo[i][inc][dec];

            // Choice 1: Do not include arr[i] in either subsequence
            int ans = solve(i + 1, inc, dec, arr);

            // Choice 2: Add arr[i] to the strictly increasing subsequence
            if (arr[i] > inc) {
                ans = max(ans, 1 + solve(i + 1, arr[i], dec, arr));
            }

            // Choice 3: Add arr[i] to the strictly decreasing subsequence
            if (arr[i] < dec) {
                ans = max(ans, 1 + solve(i + 1, inc, arr[i], arr));
            }

            return memo[i][inc][dec] = ans;
        }

    public:
        int minCount(vector<int>& arr) {
            int n = arr.size();
            memset(memo, -1, sizeof(memo));

            // Initial increasing tail is 0, decreasing tail is 101
            int maxIncluded = solve(0, 0, 101, arr);

            return n - maxIncluded;
        }
 
};