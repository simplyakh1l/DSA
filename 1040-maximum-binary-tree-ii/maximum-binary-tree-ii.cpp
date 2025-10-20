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
    void ino(TreeNode* nde,vector<int>&a){
        if(nde==NULL)return;
        ino(nde->left,a);
        a.push_back(nde->val);
        ino(nde->right,a);
    }
    int fmi(vector<int>&a,int l,int r){
        int ind=l;
        int maxi=a[l];
        for(int i=l;i<=r;i++){
            if(a[i]>maxi){
                maxi=a[i];
                ind=i;
            }
        }
        return ind;
    }
    TreeNode* sol(vector<int>&a,int l,int r){
        if(l>r)return NULL;
    
        int ri=fmi(a,l,r);
        TreeNode* root=new TreeNode(a[ri]);

        TreeNode* ls=sol(a,l,ri-1);
        TreeNode* rs=sol(a,ri+1,r);

        root->left=ls;
        root->right=rs;

        return root;
        
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int>a;
        ino(root,a);
        a.push_back(val);

        root=sol(a,0,a.size()-1);
        return root;

        
        
    }
};