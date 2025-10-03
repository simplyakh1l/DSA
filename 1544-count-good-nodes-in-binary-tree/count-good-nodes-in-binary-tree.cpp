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
    void sol(TreeNode* nde,int pmax,int &cnt){
        if(nde==NULL)return;

        if(nde->val>=pmax)cnt++;

        sol(nde->left,max(pmax,nde->val),cnt);
        sol(nde->right,max(pmax,nde->val),cnt);

    }
    int goodNodes(TreeNode* root) {
    
        int cmax=root->val;
        int cnt=0;
        sol(root,cmax,cnt);

        return cnt;
    }
};