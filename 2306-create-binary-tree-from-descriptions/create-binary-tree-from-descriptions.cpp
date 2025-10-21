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
    TreeNode* sol(int root,unordered_map<int,vector<int> >&mpp){
        TreeNode* nde=new TreeNode(root);

        int lt;
        int rt;
        if(mpp.find(root)!=mpp.end()){
            lt=mpp[root][0];
            rt=mpp[root][1];
        }

        if(lt==-1){
            nde->left=NULL;
        }
        else{
            TreeNode* ls=sol(lt,mpp);
            nde->left=ls;
        }
        if(rt==-1){
            nde->right=NULL;
        }
        else{
            TreeNode* rs=sol(rt,mpp);
            nde->right=rs;
        }
        return nde;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& a) {
        unordered_map<int,vector<int> >mpp;
        unordered_set<int>ic; //ischild???
        //parent->child,l/r
        for(auto it:a){
            if(mpp.find(it[0])==mpp.end())mpp[it[0]]=vector<int>(2,-1);
            if(it[2]==1)mpp[it[0]][0]=it[1];
            else mpp[it[0]][1]=it[1];

            ic.insert(it[1]);
        }
        int rval;
        for(auto it:a){
            if(ic.find(it[0])==ic.end()){
                rval=it[0];
                break;
            }
        }

        TreeNode* root=sol(rval,mpp);
        return root;
    }
};