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
    void sol(TreeNode* nde,long long &sm){
        if(nde==NULL)return;
        sol(nde->right,sm);
        sm+=nde->val;
        nde->val=sm;
        sol(nde->left,sm);
    }
    TreeNode* convertBST(TreeNode* root) {
        long long sm=0;
        sol(root,sm);
        return root;
        
    }
};