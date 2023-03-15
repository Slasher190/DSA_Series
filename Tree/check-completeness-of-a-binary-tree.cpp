class Solution {
public:
    int NodeCount(TreeNode *root){
        if (root == NULL){
            return 0;
        }
        int a = 1 + NodeCount(root->left) + NodeCount(root->right);
        return a;
    }
    bool isCT(TreeNode *root, int no_node, int index){
        if (!root) return true;
        if(index >= no_node) return false;
        return (isCT(root->left, no_node, 2*index + 1) && isCT(root->right, no_node, 2*index + 2));
    }
    bool isCompleteTree(TreeNode* root) {
        return isCT(root, NodeCount(root), 0);
    }
};
// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
