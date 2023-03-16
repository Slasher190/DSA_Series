class Solution {
private:
    // unordered_map<int, int> pos;
    unordered_map<int, int> in;
public:
    TreeNode* break_( vector<int> &ino, vector<int> &poso, int iS, int iE, int &ind){
        if (iS > iE) return NULL;
        int curr = poso[ind];
        TreeNode *Node = new TreeNode(curr);
        ind--;
        if (iS == iE){
            return Node;
        }
        int idx = in[curr];
        Node->right = break_(ino, poso, idx+1, iE, ind);
        Node->left = break_(ino, poso, iS, idx-1, ind);
        return Node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        for (int i=0; i<inorder.size(); i++){
            in[inorder[i]] = i;
        }
        int n = postorder.size()-1;
        return break_(inorder, postorder, 0, n, n);
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
