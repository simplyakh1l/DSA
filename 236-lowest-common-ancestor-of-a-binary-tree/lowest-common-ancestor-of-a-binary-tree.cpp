/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sol(TreeNode* nde,TreeNode* p,TreeNode* q){
        if(nde==NULL)return NULL;

        if(nde==p || nde==q)return nde;
        TreeNode* l=sol(nde->left,p,q);
        TreeNode* r=sol(nde->right,p,q);


        if(l && r)return nde;
        if(l)return l;
        if(r)return r;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=sol(root,p,q);
        return ans;
    }
};