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
class FindElements {
public:
    TreeNode* rt;
    FindElements(TreeNode* root) {
        queue<pair<int,TreeNode* > >q;
        q.push({0,root});
        while(q.size()){
            TreeNode* nde=q.front().second;
            int tmp=q.front().first;
            nde->val=tmp;
            q.pop();

            if(nde->left){
                q.push({(2*tmp+1),nde->left});
            }
            if(nde->right){
                q.push({2*tmp+2,nde->right});
            }
        }
        rt=root;
    }
    
    bool find(int target) {
        int f=0;
        queue<TreeNode*>q;
        q.push(rt);
        while(q.size() && f==0){
            TreeNode* nde=q.front();
            q.pop();

            if(nde->val==target)f=1;
            if(nde->left)q.push(nde->left);
            if(nde->right)q.push(nde->right);
        }
        return f;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */