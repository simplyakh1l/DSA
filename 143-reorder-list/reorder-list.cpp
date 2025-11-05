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

    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)return;
        ListNode* s=head;
        ListNode* f=head;

        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }

        ListNode* h2=s->next;
        s->next=NULL;
        rev(h2,h2);

        ListNode* t1=head;
        ListNode* t2=h2;
        while(t1 && t2){
            ListNode *n1=t1->next;
            ListNode* n2=t2->next;

            t1->next=t2;
            t2->next=n1;

            t1=n1;
            t2=n2;
        }


    }
};