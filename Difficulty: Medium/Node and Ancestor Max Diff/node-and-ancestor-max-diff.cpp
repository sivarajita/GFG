/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  int solve(Node* root, int &max_diff) {
          if (!root) return INT_MAX;

          // A leaf node has no descendants
          if (!root->left && !root->right) {
              return root->data;
          }

          // Find minimum values in left and right subtrees
          int left_min = solve(root->left, max_diff);
          int right_min = solve(root->right, max_diff);

          // Minimum among all descendants
          int descendant_min = std::min(left_min, right_min);

          // Maximize A - B (where A is root->data and B is descendant_min)
          max_diff = std::max(max_diff, root->data - descendant_min);

          // Return minimum value in the current subtree rooted at `root`
          return std::min(root->data, descendant_min);
      }

  public:
      int maxDiff(Node* root) {
          int max_diff = INT_MIN;
          solve(root, max_diff);
          return max_diff;
        
    }
};