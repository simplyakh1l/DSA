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
    void sol(TreeNode* p, TreeNode* q, int &f){
        if(p==NULL && q==NULL)return;

        else if(p==NULL){
            f=0;
            return;
        }
        else if(q==NULL){
            f=0;
            return;
        }

        else if(p->val!=q->val){
            f=0;
            return;

        }

        sol(p->left,q->left,f);
        sol(p->right,q->right,f);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int f=1;

        sol(p,q,f);

        return f;
        
    }
};