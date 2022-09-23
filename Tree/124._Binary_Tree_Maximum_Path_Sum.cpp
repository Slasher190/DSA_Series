/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_path_Tree(TreeNode* root, int& path_sum){
        if (root == NULL){
            return 0;
        }
        int lh = max(0,max_path_Tree(root->left, path_sum)); //finding left tree of max path sum
        int rh = max(0,max_path_Tree(root->right, path_sum)); // finding right tree of max path sum
        path_sum = max(path_sum, lh+rh+root->val); // now add to the root 
        return root->val + max(lh,rh); // return max of it
    }
    int maxPathSum(TreeNode* root) {
        int path_sum = INT_MIN;
        max_path_Tree(root, path_sum);
        return path_sum;
    }
};
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
