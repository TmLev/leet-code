 struct ListNode {
     int val{0};
     ListNode* next{nullptr};

     ListNode() = default;
     ListNode(int x) : val(x) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode  dummy;
    ListNode* merged = &dummy;

    while (l1 || l2) {
        auto next = [&]() -> ListNode** {
            if (l1 && l2) {
                return &(l1->val < l2->val ? l1 : l2);
            } else {
                return &(l1 ? l1 : l2);
            }
        }();

        merged->next = new ListNode((*next)->val);
        *next = (*next)->next;
        merged = merged->next;
    }

    return dummy.next;
}

