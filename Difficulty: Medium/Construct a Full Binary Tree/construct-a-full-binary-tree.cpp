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
private:
    Node* buildTree(vector<int>& pre, int preStart, int preEnd,
                    vector<int>& preMirror, int mirrorStart, int mirrorEnd,
                    unordered_map<int, int>& mirrorMap) {
        if (preStart > preEnd || mirrorStart > mirrorEnd) {
            return nullptr;
        }

        // Create the root node
        Node* root = new Node(pre[preStart]);

        // Base case: If node has no children (leaf node)
        if (preStart == preEnd) {
            return root;
        }

        // Root of the left subtree in the original tree
        int leftVal = pre[preStart + 1];

        // Find index of leftVal in preMirror
        int idx = mirrorMap[leftVal];

        // Number of nodes in the left subtree
        int leftLen = mirrorEnd - idx + 1;

        // Recursively construct left and right subtrees
        root->left = buildTree(pre, preStart + 1, preStart + leftLen,
                               preMirror, idx, mirrorEnd, mirrorMap);

        root->right = buildTree(pre, preStart + leftLen + 1, preEnd,
                                preMirror, mirrorStart + 1, idx - 1, mirrorMap);

        return root;
    }

public:
    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {
        int n = pre.size();
        unordered_map<int, int> mirrorMap;

        // Store indices of preMirror elements for O(1) lookups
        for (int i = 0; i < n; i++) {
            mirrorMap[preMirror[i]] = i;
        }

        return buildTree(pre, 0, n - 1, preMirror, 0, n - 1, mirrorMap);
    }
};