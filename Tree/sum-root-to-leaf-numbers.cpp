class Solution {
private:
    int sum = 0;
public:
    void helper(TreeNode* root, string& sf) {
        if (!root) {
            return;
        }
        sf += to_string(root->val);
        if (!root->left && !root->right) {
            sum += stoi(sf);
        } else {
            helper(root->left, sf);
            helper(root->right, sf);
        }
        sf.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string p;
        helper(root, p);
        return sum;
    }
};

// https://leetcode.com/problems/sum-root-to-leaf-numbers/
