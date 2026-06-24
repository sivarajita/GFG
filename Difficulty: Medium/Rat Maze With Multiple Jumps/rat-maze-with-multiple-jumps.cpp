class Solution {
public:
    bool solve(int i, int j, int n, vector<vector<int>>& mat, vector<vector<int>>& ans, vector<vector<bool>>& failed) {
        // Base Case: Destination reached
        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        // Boundary check, obstacle check, or if we already know this cell is a dead end
        if (i >= n || j >= n || mat[i][j] == 0 || failed[i][j]) {
            return false;
        }

        // Mark the current cell as part of the tentative solution path
        ans[i][j] = 1;

        int maxJumps = mat[i][j];
        for (int step = 1; step <= maxJumps; ++step) {
            // 1. Try moving Forward (Right) first
            if (solve(i, j + step, n, mat, ans, failed)) {
                return true;
            }
            // 2. Try moving Downward second
            if (solve(i + step, j, n, mat, ans, failed)) {
                return true;
            }
        }

        // Backtrack: Unmark from solution path
        ans[i][j] = 0;
        
        // Memoize: Mark this cell as a confirmed dead end so future paths skip it
        failed[i][j] = true; 
        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        // Keeps track of cells that cannot reach the destination
        vector<vector<bool>> failed(n, vector<bool>(n, false));

        if (solve(0, 0, n, mat, ans, failed)) {
            return ans;
        }

        return {{-1}};
    }
};