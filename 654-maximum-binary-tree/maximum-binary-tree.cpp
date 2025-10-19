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
    int mind(vector<int>&nums,int l,int r){
        int maxi=INT_MIN;
        int mi=-1;
        for(int i=l;i<=r;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                mi=i;
            }
        }
        return mi;
    }
    TreeNode* sol(vector<int>&nums,int l,int r){
        if(l>r)return NULL;
        if(l==r)return new TreeNode(nums[l]);

        int rind=mind(nums,l,r);
        TreeNode* root=new TreeNode(nums[rind]);

        TreeNode* ls=sol(nums,l,rind-1);
        TreeNode* rs=sol(nums,rind+1,r);

        root->left=ls;
        root->right=rs;
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        TreeNode* root=sol(nums,0,n-1);


        return root;

        
    }
};