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
}; */

class Solution {
  private:
      Node* findLCA(Node* root, int p, int q) {
          if (!root || root->data == p || root->data == q) 
              return root;

          Node* left = findLCA(root->left, p, q);
          Node* right = findLCA(root->right, p, q);

          if (left && right) return root;
          return left ? left : right;
      }

      bool countTurns(Node* curr, int target, bool isLeft, int& turns) {
          if (!curr) return false;

          if (curr->data == target) return true;

          // Moving Left
          if (countTurns(curr->left, target, true, turns)) {
              if (!isLeft) turns++; // Direction changed from right to left
              return true;
          }

          // Moving Right
          if (countTurns(curr->right, target, false, turns)) {
              if (isLeft) turns++;  // Direction changed from left to right
              return true;
          }

          return false;
      }

  public:
      int numberOfTurns(Node* root, int p, int q) {
          Node* lca = findLCA(root, p, q);
          if (!lca) return -1;

          int turns = 0;

          // Case 1: One node is the ancestor of another
          if (lca->data == p || lca->data == q) {
              int target = (lca->data == p) ? q : p;

              // Search in both left and right subtrees of LCA
              countTurns(lca->left, target, true, turns);
              countTurns(lca->right, target, false, turns);

              return (turns == 0) ? -1 : turns;
          }

          // Case 2: Nodes lie in different subtrees of LCA
          countTurns(lca->left, p, true, turns);
          countTurns(lca->right, p, false, turns);
          countTurns(lca->left, q, true, turns);
          countTurns(lca->right, q, false, turns);

          // +1 for the turn across the LCA itself
          return turns + 1;
      }
  };