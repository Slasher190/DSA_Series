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
    vector<int> ls;
    void Tree(TreeNode* root, int tar, vector<vector<int>> &v, vector<int> path){
        if (!root) return;
        tar = tar - root->val; //subtract via node value
        path.push_back(root->val); //pushing to path vector
        if(!root->left && !root->right){   //checking for not null value
            if (tar == 0){
                v.push_back(path); //push to main vector
            }
        }
        
        Tree(root->left,tar,v,path);
        Tree(root->right,tar,v,path);
        path.pop_back(); //backtracking
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        Tree(root, targetSum, ans, v);
        return ans;
    }
};

// https://leetcode.com/problems/path-sum-ii/
