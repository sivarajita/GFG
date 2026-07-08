class Solution {
private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& mat, int n, int m) {
        vis[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            // Check boundaries, if neighbor is unvisited, and if neighbor height >= current height
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] >= mat[r][c]) {
                dfs(nr, nc, vis, mat, n, m);
            }
        }
    }

public:
    int countCoordinates(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();

        vector<vector<bool>> visP(n, vector<bool>(m, false));
        vector<vector<bool>> visQ(n, vector<bool>(m, false));

        // 1. DFS for Top and Bottom boundaries
        for (int j = 0; j < m; j++) {
            // Top row belongs to Station P
            if (!visP[0][j]) dfs(0, j, visP, mat, n, m);
            // Bottom row belongs to Station Q
            if (!visQ[n - 1][j]) dfs(n - 1, j, visQ, mat, n, m);
        }

        // 2. DFS for Left and Right boundaries
        for (int i = 0; i < n; i++) {
            // Left column belongs to Station P
            if (!visP[i][0]) dfs(i, 0, visP, mat, n, m);
            // Right column belongs to Station Q
            if (!visQ[i][m - 1]) dfs(i, m - 1, visQ, mat, n, m);
        }

        // 3. Count towers that can reach both stations
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visP[i][j] && visQ[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};