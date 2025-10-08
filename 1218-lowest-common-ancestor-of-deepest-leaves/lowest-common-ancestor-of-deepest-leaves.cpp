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
    void findh(TreeNode* nde,int &cnt,int ch,int &mh){
        if(nde==NULL)return;
        ch++;
        if(ch>mh){
            mh=ch;
            cnt=1;
        }
        else if(ch==mh)cnt++;

        findh(nde->left,cnt,ch,mh);
        findh(nde->right,cnt,ch,mh); 
    }

    int sol(TreeNode* nde,TreeNode* &ans,int ch,int &cnt,int &maxh){
        if(nde==NULL)return 0;
        ch++;
        
        int l=sol(nde->left,ans,ch,cnt,maxh);
        int r=sol(nde->right,ans,ch,cnt,maxh);
       
        if(ch==maxh){
            if(l+r+1==cnt && ans==NULL)ans=nde;
            return 1;
        }
        if(l+r==cnt && ans==NULL)ans=nde;

        return l+r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxh=0;
        int ch=0;
        int cnt=0;
        findh(root,cnt,ch,maxh);

        ch=0;
        TreeNode* ans=NULL;
        int tmp=sol(root,ans,ch,cnt,maxh);
     
        return ans;
    }
};