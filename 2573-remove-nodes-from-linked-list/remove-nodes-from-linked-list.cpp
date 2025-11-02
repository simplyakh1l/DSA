class Solution {
public:
    ListNode* rev(ListNode* nde, ListNode* &hd) {
        if (nde->next == NULL) {
            hd = nde;
            return nde;
        }
        ListNode* nex = rev(nde->next, hd);
        nex->next = nde;
        nde->next = NULL;
        return nde;
    }

    ListNode* removeNodes(ListNode* head) {
        rev(head, head);

        int maxi = head->val;
        ListNode* tmp = head;
        ListNode* prev = NULL;

        while (tmp) {
            if (tmp->val >= maxi) {
                maxi = tmp->val;
                prev = tmp;
                tmp = tmp->next;
            } else {
                ListNode* nex = tmp->next;
                if(prev)prev->next = tmp->next;
            
                tmp = nex;
            }
        }

        rev(head, head);
        return head;
    }
};
