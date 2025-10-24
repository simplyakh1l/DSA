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
    int getlvl(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        int n=0;
        while(q.size()){
            int len=q.size();
            while(len--){
                TreeNode* nde=q.front();
                q.pop();

                if(nde->left)q.push(nde->left);
                if(nde->right)q.push(nde->right);
            }
            n++;
        }
        return n;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int n=getlvl(root);
        int sz=pow(2,n)-1;
        vector<vector<string> >ans(n,vector<string>(sz,""));

        queue<pair<TreeNode*,pair<int,int> > >q;
        sz--;
        sz/=2;
        q.push({root,{0,sz}});

        while(q.size()){
            int len=q.size();

            while(len--){
                pair<TreeNode*,pair<int,int> > tmp=q.front();
                q.pop();

                TreeNode* nde=tmp.first;
                int cr=tmp.second.first;
                int cc=tmp.second.second;

                ans[cr][cc]=to_string(nde->val);

                if(nde->left){
                    q.push({nde->left,{cr+1,cc-pow(2,n-cr-2)}});
                }
                if(nde->right){
                    q.push({nde->right,{cr+1,cc+pow(2,n-cr-2)}});
                }
            }
        }
        return ans;
    }
};