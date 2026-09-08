class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        int n = mat.size();
                int m = mat[0].size();
                int len = word.length();

                // 8 directions: up, down, left, right, and 4 diagonals
                int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
                int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

                vector<vector<int>> ans;

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (mat[i][j] != word[0]) continue;

                        // If word is of length 1, it's an immediate match
                        if (len == 1) {
                            ans.push_back({i, j});
                            continue;
                        }

                        // Check all 8 directions
                        for (int dir = 0; dir < 8; ++dir) {
                            int r = i + dx[dir];
                            int c = j + dy[dir];
                            int k = 1;

                            while (k < len) {
                                if (r < 0 || r >= n || c < 0 || c >= m || mat[r][c] != word[k]) {
                                    break;
                                }
                                r += dx[dir];
                                c += dy[dir];
                                k++;
                            }

                            // If the entire word matched in this direction
                            if (k == len) {
                                ans.push_back({i, j});
                                break; // Stop checking other directions for (i, j)
                            }
                        }
                    }
                }

                return ans;
    }
};