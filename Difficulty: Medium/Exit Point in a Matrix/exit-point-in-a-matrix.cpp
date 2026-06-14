class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        // Direction vectors mapped in clockwise order: Right, Down, Left, Up
        int dRow[] = {0, 1, 0, -1};
        int dCol[] = {1, 0, -1, 0};
        
        int r = 0, c = 0;     // Start position
        int dirIdx = 0;       // Start direction (0 = Right)
        
        // Track the last valid position inside the matrix
        int lastR = 0, lastC = 0;
        
        while (r >= 0 && r < n && c >= 0 && c < m) {
            // Keep track of the current valid position before we potentially step out
            lastR = r;
            lastC = c;
            
            if (mat[r][c] == 1) {
                dirIdx = (dirIdx + 1) % 4; // Turn 90 deg right (clockwise)
                mat[r][c] = 0;             // Change the cell value to 0
            }
            
            // Move forward in the current direction
            r += dRow[dirIdx];
            c += dCol[dirIdx];
        }
        
        return {lastR, lastC};
    }
};