/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void chck(TreeNode* nde,ListNode* ll, int &f){
        if(ll==NULL){
            f=1;
            return;
        }
        if(nde==NULL || nde->val!=ll->val)return;
        chck(nde->left,ll->next,f);
        chck(nde->right,ll->next,f);
    }
    void sol(TreeNode* nde,ListNode* ll,int &f){
        if(nde==NULL)return;
        if(nde->val==ll->val){
            chck(nde,ll,f);
        }
        sol(nde->left,ll,f);
        sol(nde->right,ll,f);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        int ans=0;
        sol(root,head,ans);
        return ans;
    }
};