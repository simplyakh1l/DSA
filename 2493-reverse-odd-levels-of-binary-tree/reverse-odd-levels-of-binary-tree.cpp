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
    TreeNode* reverseOddLevels(TreeNode* &root) {
        queue<TreeNode*>q;
        q.push(root);
        int lvl=0;

        while(q.size()){
            int len=q.size();
            stack<int>st;

            if(lvl%2==1){
                for(int i=0;i<len;i++){
                    TreeNode* nde=q.front(); q.pop();
                    st.push(nde->val);
                    q.push(nde);
                }
            }

            for(int i=0;i<len;i++){
                TreeNode* nde=q.front();
                if(lvl%2==1){
                    nde->val=st.top();
                    st.pop();
                }
                q.pop();

                if(nde->left)q.push(nde->left);
                if(nde->right)q.push(nde->right);
            }
            lvl++;
        }
        return root;
    }

};