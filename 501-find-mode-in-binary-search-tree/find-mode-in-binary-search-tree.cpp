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
    void dfs(TreeNode* nde,unordered_map<int,int>&mpp,int &mff,int &mfe){
        if(nde==NULL)return;

        mpp[nde->val]++;
        if(mpp[nde->val]>mff){
            mff=mpp[nde->val];
            mfe=nde->val;
        }
        

        dfs(nde->left,mpp,mff,mfe);
        dfs(nde->right,mpp,mff,mfe);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mpp;
        int mfe=root->val;
        int mff=1;
        dfs(root,mpp,mff,mfe);

        vector<int>ans;
        for(auto it:mpp){
            if(it.second==mff){
                ans.push_back(it.first);
            }
        }
        return ans;

        
    }
};