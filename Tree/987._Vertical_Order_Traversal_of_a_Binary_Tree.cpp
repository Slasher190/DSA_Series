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
    class vt_cor{  //class for storing coordinates of node
        public:
        TreeNode* root;
        int vrt_lvl;
        int hor_lvl;
        vt_cor(TreeNode* root, int vrt_lvl, int hor_lvl){
            this->root = root;
            this->vrt_lvl = vrt_lvl;
            this->hor_lvl = hor_lvl;
        }
    };
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,unordered_map<int,multiset<int>>> mp; //data structure for storing nodes value and its cordinate
        vector<vector<int>> ans; //it will store the value of each verticle level
        queue<vt_cor> que;
        que.push({root,0,0}); //initialize root (0,0)  --> (verticle,horizantal)
        int mn_vrt=0,mn_hor=0; //it will store the extreme left and extreme top coordinate
        int mx_vrt=0,mx_hor=0; //extreme right and down 
        while(!que.empty()){
            int n = que.size();
            while(n--){
                vt_cor rm = que.front();
                que.pop();
                
                mp[rm.vrt_lvl][rm.hor_lvl].insert(rm.root->val);
                mn_vrt = min(mn_vrt,rm.vrt_lvl);
                mx_vrt = max(mx_vrt,rm.vrt_lvl);
                mx_hor = max(mx_hor,rm.hor_lvl);
                mn_hor = min(mn_hor,rm.hor_lvl);
                
                if (rm.root->left != NULL){
                    que.push({rm.root->left,rm.vrt_lvl-1,rm.hor_lvl+1}); //pushing in que left where -1 and down with level +1
                }
                if (rm.root->right != NULL){
                    que.push({rm.root->right,rm.vrt_lvl+1,rm.hor_lvl+1});
                }
                
            }
        }
        for(int i=mn_vrt;i<=mx_vrt;i++){     
            vector<int> temp;
            for(int j=mn_hor;j<=mx_hor;j++){
                
                if(mp[i][j].size() != 0){
                    for(auto k:mp[i][j]){
                        temp.push_back(k);    //pushing in tempeorory vactor 
                    }   
                }
            }
            ans.push_back(temp); //pushing int to ans
        }
        return ans;
    }
};
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
