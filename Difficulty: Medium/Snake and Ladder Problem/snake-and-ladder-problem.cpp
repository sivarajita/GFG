class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        int target = n * n;

        // 1-based indexing for the board
        std::vector<int> board(target + 1);
        for (int i = 1; i <= target; ++i) {
            board[i] = i;
        }

        // Populate ladders
        for (size_t i = 0; i < lad.size(); i += 2) {
            board[lad[i]] = lad[i + 1];
        }

        // Populate snakes
        for (size_t i = 0; i < sn.size(); i += 2) {
            board[sn[i]] = sn[i + 1];
        }

        // BFS initialization: store pairs of {current_cell, moves_count}
        std::queue<std::pair<int, int>> q;
        std::vector<bool> visited(target + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            if (curr == target) return dist;

            // Try all possible dice throws from 1 to 6
            for (int roll = 1; roll <= 6; ++roll) {
                int next = curr + roll;
                if (next > target) break;

                int dest = board[next];

                if (!visited[dest]) {
                    visited[dest] = true;
                    q.push({dest, dist + 1});
                }
            }
        }

        return -1;
    }
};