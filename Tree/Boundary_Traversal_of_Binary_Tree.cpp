#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>*root){ // checking for leaf node
    if (root->left == NULL && root->right == NULL){
        return true;
    }
    return false;
}

void addLeft(TreeNode<int> *root, vector<int> &v){ //adding left side of the tree 
    TreeNode<int>* temp = root->left;
    while(temp != NULL){
        if (!isLeaf(temp)) v.push_back(temp->data);
        if (temp->left != NULL){
            temp = temp->left;
        }
        else{
            temp = temp->right; //if left not exist then go for right
        }
    }
}

void addRight(TreeNode<int> *root, vector<int> &v){ //adding for the right same
    TreeNode<int>* temp = root->right;
    stack<int> st; //for anticlock-wise senario
    while(temp != NULL){
        if(!isLeaf(temp)) st.push(temp->data);
        if(temp->right != NULL) temp = temp->right;
        else temp = temp->left;
    }
    while(!st.empty()){
        v.push_back(st.top()); //for anti-clockwise 
        st.pop();
    }
}

void addLeaf(TreeNode<int> *temp, vector<int> &v){ //adding all leafs which remains 
    if (isLeaf(temp)){
        v.push_back(temp->data);
        return;
    }
    if (temp->left) addLeaf(temp->left,v);
    if (temp->right) addLeaf(temp->right,v);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if (root == NULL){
        return ans;
    }
    if (!isLeaf(root)) ans.push_back(root->data);
    addLeft(root,ans);
    addLeaf(root,ans);
    addRight(root,ans);
//     cout<<ans.size()<<endl;
    return ans;
}
// https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1380976
