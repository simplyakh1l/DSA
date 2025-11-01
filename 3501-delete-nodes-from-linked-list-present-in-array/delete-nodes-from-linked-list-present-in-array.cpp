class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> mpp(nums.begin(), nums.end());
        
        while (head && mpp.find(head->val) != mpp.end()) {
            head = head->next;
        }
        
        if (!head) return nullptr;

        ListNode* temp = head;
        ListNode* last = nullptr;
        
        while (temp) {
            if (mpp.find(temp->val) == mpp.end()) {
                last = temp;
                temp = temp->next;
            } else {
                if (last) {
                    last->next = temp->next;
                }
                temp = temp->next;
            }
        }
        
        return head;
    }
};
