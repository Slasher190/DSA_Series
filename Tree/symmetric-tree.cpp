class Solution {
public:
    bool helper(TreeNode *leftN, TreeNode *rightN){
        if (leftN == NULL && rightN == NULL) return true;
        if (leftN == NULL || rightN == NULL || leftN->val != rightN->val){
            return false;
        }
        return helper(leftN->left, rightN->right) && helper(leftN->right, rightN->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};

// https://leetcode.com/problems/symmetric-tree/
