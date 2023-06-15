// All questions of Linked Lists are to be solved in O(1) space;
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* curr = A;
    while(curr != NULL && curr->next != NULL){
        swap(curr->val, curr->next->val);
        curr = curr->next->next;
    }
    return A;
}