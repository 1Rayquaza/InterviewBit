// Draw diagrams to see the connections clearly

ListNode* Solution::insertionSortList(ListNode* A) {
    if(A->next == NULL) return A;
    ListNode* curr = A->next;
    ListNode* currPrev = A;
    while(curr != NULL){
        int key = curr->val;
        ListNode* j = A;
        ListNode* prev = NULL;
        ListNode* next = curr->next;
        while(j != curr && j->val < key){
            prev = j;
            j = j->next;    
        }
        if(prev == NULL) A = curr;
        else prev->next = curr;  // if NULL, i.e. starting mei insert krna h toh
        curr->next = j;
        if(key > currPrev->val){
            currPrev = curr;
        }
        currPrev->next = next;
        curr = next;
    }
    return A;
}
