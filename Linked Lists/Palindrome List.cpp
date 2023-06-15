// we need to check if reverse of 2nd half is equal to first half excluding middle element(if any)
int Solution::lPalin(ListNode* A) {
    ListNode* curr = A;
    int c=0;
    while(curr != NULL){
        c++;
        curr = curr->next;
    }
    int check = (c-1)/2;
    
    ListNode* revcurr = A;
    check = check-1;    // check the jumps required
    while(check--){
        revcurr = revcurr->next;
    }
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while(revcurr != NULL){
        next = revcurr->next;  // store current information, to be used next
        revcurr->next = prev;  // reverse a little
        prev = revcurr;
        revcurr = next;
    }
    
    //comparison
    curr = A;
    revcurr = prev; // previously last element ka next became NULL, however we need last element which is stored in prev(before NULL)
    while(revcurr != NULL){
        if(curr->val != revcurr->val){
            return 0;
        }
        curr = curr->next;
        revcurr = revcurr->next;
    }
    return 1;
}

    
    
