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
    TreeNode* sol(TreeNode* nde,int &t){
        if(nde==NULL)return NULL;
        if(nde->left==NULL && nde->right==NULL && nde->val==t)return nde;

        TreeNode* l=sol(nde->left,t);
        TreeNode* r=sol(nde->right,t);

        if(l)nde->left=NULL;
        if(r)nde->right=NULL;
        
        if(nde->left==NULL && nde->right==NULL && nde->val==t)return nde;
        return NULL;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* tmp=sol(root,target);
        if(tmp)return NULL;
        return root;
    }
};