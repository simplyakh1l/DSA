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
    ListNode* rev(ListNode* nde,ListNode* &head){
        if(nde->next==NULL){
            head=nde;
            return nde;
        }
        ListNode* nex=rev(nde->next,head);
        nex->next=nde;
        nde->next=NULL;
        return nde;
    }
    int pairSum(ListNode* h1) {
        ListNode* s=h1;
        ListNode* f=h1;
        while(s && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* t2=s->next;
        s->next=NULL;
        rev(h1,h1);
        ListNode* t1=h1;

        
       

        int maxi=0;
        while(t1 && t2){
            maxi=max(t1->val+t2->val,maxi);
            t1=t1->next;
            t2=t2->next;
        }
        return maxi;

        
    }
};