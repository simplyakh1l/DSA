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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>,greater<long long> > minh;
        queue<TreeNode*>q;
        q.push(root);

        int lvl=0;

        while(q.size()){
            int len=q.size();
            long long sm=0;
            while(len--){
                TreeNode* nde=q.front();
                q.pop();

                sm+=nde->val;

                if(nde->left)q.push(nde->left);
                if(nde->right)q.push(nde->right);
            }
            minh.push(sm);
            if(minh.size()>k)minh.pop();
            lvl++;
        }
        if(lvl<k)return -1;
        return minh.top();
    }
   
};