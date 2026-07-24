/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
    private:
    void solve(Node* node, int expected_val, int curr_len, int& max_len) {
        if (!node) return;

        // Check if current node continues the consecutive path
        if (node->data == expected_val) {
            curr_len++;
        } else {
            curr_len = 1; // Reset length if path breaks
        }

        max_len = max(max_len, curr_len);

        // Recurse for left and right children expecting (current data + 1)
        solve(node->left, node->data + 1, curr_len, max_len);
        solve(node->right, node->data + 1, curr_len, max_len);
    }

public:
    int longestConsecutive(Node* root) {
        if (!root) return -1;

        int max_len = 0;
        // Start traversal: initial expected value is root's data
        solve(root, root->data, 0, max_len);

        // Return -1 if no consecutive sequence of length >= 2 exists
        return (max_len > 1) ? max_len : -1;
    }
};