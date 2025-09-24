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
    void idn(TreeNode* n1,TreeNode* n2,int &f){
        if(n1==NULL && n2==NULL)return;
        else if(n1==NULL || n2==NULL || n1->val!=n2->val || f==0){
            f=0;
            return;
        }
        idn(n1->left,n2->left,f);
        idn(n1->right,n2->right,f);
        return;
    }

    void sol(TreeNode* n,TreeNode* sn,int &ans){
        if(n==NULL || ans==1)return;
        
        if(n->val==sn->val){
            int f=1;
            idn(n,sn,f);
            if(f==1){
                ans=1;
            return;
            }
        }
        sol(n->left,sn,ans);
        sol(n->right,sn,ans);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        int ans=0;

        sol(root,subRoot,ans);

        return ans;
    }
};