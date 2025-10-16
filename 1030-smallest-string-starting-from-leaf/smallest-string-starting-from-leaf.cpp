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
    void sol(TreeNode* nde,string tmp,string &ans){
        if(nde==NULL)return;

        char c='a'+nde->val;
        tmp=c+tmp;

        sol(nde->left,tmp,ans);
        sol(nde->right,tmp,ans);

        if(nde->left==NULL && nde->right==NULL){
            if(tmp<ans || ans=="")ans=tmp;
            return;
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        string tmp="";
        sol(root,tmp,ans);
        return ans;
    }
};