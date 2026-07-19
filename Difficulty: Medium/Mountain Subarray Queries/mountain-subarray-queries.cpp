class Solution {
public:
    vector<bool> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> up(n), down(n);

        // up[i] = farthest index reachable from i by non-decreasing sequence
        up[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                up[i] = up[i + 1];
            else
                up[i] = i;
        }

        // down[i] = farthest index reachable from i by non-increasing sequence
        down[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1])
                down[i] = down[i + 1];
            else
                down[i] = i;
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            // Go up from l, then down
            int peak = up[l];

            ans.push_back(down[peak] >= r);
        }

        return ans;
    }
};