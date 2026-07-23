/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    void solve(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        
        // Root -> Left -> Right
        ans.push_back(root->data);
        solve(root->left, ans);
        solve(root->right, ans);
    }
    
  public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};