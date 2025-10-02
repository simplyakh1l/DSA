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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tmp=head;
        while(tmp && tmp->next){
            int cval=tmp->val;
            ListNode* nex=tmp->next;
            int nval=nex->val;
            ListNode* gc=new ListNode(__gcd(cval,nval));
            tmp->next=gc;
            gc->next=nex;
            tmp=nex;
        }
        return head;
    }
};