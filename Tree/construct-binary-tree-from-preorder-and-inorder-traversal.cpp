class Solution {
private:
    unordered_map<int, int> in;
public:
    TreeNode* tree(vector<int> &pre, vector<int> &ino, int is, int ie, int &idx){
        if (is > ie) return NULL;
        int curr = pre[idx];
        idx++;
        TreeNode* Node = new TreeNode(curr);
        if (is == ie){
            return Node;
        }
        int iidx = in[curr];
        Node->left = tree(pre, ino, is, iidx-1, idx);
        Node->right = tree(pre, ino, iidx+1, ie, idx); // fix typo here
        return Node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); i++){
            in[inorder[i]] = i;
        }
        int n = preorder.size()-1;
        int i=0;
        return tree(preorder, inorder, 0, n, i);
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
