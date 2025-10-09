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
    void mke(TreeNode* nde,vector<int>&a){
        if(nde==NULL)return;
        mke(nde->left,a);
        a.push_back(nde->val);
        mke(nde->right,a);
        return;
    }
    // 0   2 3 -> 0 0
    // 1 2 3 4
    TreeNode* sol(vector<int>&a,int l,int r ){
        // 2 3
        if(l>r)return NULL;
        if(l==r)return new TreeNode(a[l]);
        int i=(l+r)/2;
        TreeNode* ans=new TreeNode(a[i]);

        TreeNode* ln=sol(a,l,i-1); //1
        TreeNode* rn=sol(a,i+1,r);

        ans->left=ln;
        ans->right=rn;
        return ans;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>a;
        mke(root,a);

        TreeNode* ans=sol(a,0,a.size()-1);
        
        

        return ans;
        // 1 2 3 

        
    }
};