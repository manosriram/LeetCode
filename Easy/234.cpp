/* 1->2->1->2->1
 *
 * 1. Bring slow pointer to the middle of linked list
 * 2. Reverse the nodes after the slow node and attach it as slow->next
 * 3. Mark slow->next as the start of reversed list node.
 * 4. Start traversing the head and reverse list at the same time comparing the values.
 */


ListNode *reverse(ListNode *head) {
    ListNode *prev = NULL, *cur = head;
    while (cur) {
        ListNode *hold = cur->next;
        cur->next = prev;
        prev = cur;
        cur = hold;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *rev = reverse(slow->next);
    ListNode *cur = head;
    while (rev) {
        if (cur->val != rev->val) return false;
        
        cur = cur->next;
        rev = rev->next;
    }
    return true;
}
