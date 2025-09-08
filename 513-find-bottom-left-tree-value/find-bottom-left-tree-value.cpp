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
    void sol(TreeNode* nde,int &val,int &maxi,int cnt){
        if(nde==NULL)return;

        if(cnt>maxi){
            maxi=cnt;
            val=nde->val;
        }
        sol(nde->left,val,maxi,cnt+1);
        sol(nde->right,val,maxi,cnt+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int val=root->val;
        int cnt=0;
        int maxi=0;
        sol(root,val,maxi,cnt);

        return val;
    }
};