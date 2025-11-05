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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int> >ans(m,vector<int> (n,-1));
        ListNode* tmp=head;

        int rb=0,re=m-1,cb=0,ce=n-1;

        while(tmp && rb<=re && cb<=ce){

            for(int j=cb;j<=ce;j++){
                if(tmp==NULL)break;
                ans[rb][j]=tmp->val;
                tmp=tmp->next;
            }
            rb++;

            for(int j=rb;j<=re;j++){
                if(tmp==NULL)break;
                ans[j][ce]=tmp->val;
                tmp=tmp->next;
            }
            ce--;

            for(int j=ce;j>=cb;j--){
                if(tmp==NULL)break;
                ans[re][j]=tmp->val;
                tmp=tmp->next;
            }
            re--;

            for(int j=re;j>=rb;j--){
                if(tmp==NULL)break;
                ans[j][cb]=tmp->val;
                tmp=tmp->next;
            }
            cb++;
        }
        return ans;

        
    }
};