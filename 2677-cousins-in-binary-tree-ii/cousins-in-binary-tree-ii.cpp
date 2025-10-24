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
    void dfs(TreeNode* nde, unordered_map<int, int>& mpp, int lvl) {
        if (nde == NULL) return;
        if (mpp.find(lvl) == mpp.end()) mpp[lvl] = 0;

        mpp[lvl] += nde->val;
        dfs(nde->left, mpp, lvl + 1);
        dfs(nde->right, mpp, lvl + 1);
    }

    void sol(TreeNode* nde, TreeNode* par, unordered_map<int, int>& mpp, int lvl,unordered_map<TreeNode*,int>&psm) {
        if (nde == NULL) return;
        sol(nde->left, nde, mpp, lvl + 1,psm);
        sol(nde->right, nde, mpp, lvl + 1,psm);
        nde->val = mpp[lvl] - psm[par];
    }

    void dfs2(TreeNode* nde,unordered_map<TreeNode*,int>&psm){
        if(nde==NULL)return;
        dfs2(nde->left,psm);
        dfs2(nde->right,psm);

        if(nde->left)psm[nde]+=nde->left->val;
        if(nde->right)psm[nde]+=nde->right->val;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> mpp;
        dfs(root, mpp, 1);

        unordered_map<TreeNode*,int>psm;
        dfs2(root,psm);


        TreeNode* nr = new TreeNode(0);
        nr->left = root;
        
        sol(root, nr, mpp, 1,psm);
        root->val=0;
        return root;
    }
};
