ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode** result = &head;

    int sum = 0;
    
    while (l1 || l2 || sum) {
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        *result = new ListNode(sum % 10);
        result = &(*result)->next;
        sum /= 10;
    }
    
    return head;
}
