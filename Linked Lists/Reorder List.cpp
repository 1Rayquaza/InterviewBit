// aadha aadha sa todha hai, then reverse the second half then merge alternatively
ListNode* Solution::reorderList(ListNode* A) {
    ListNode* curr = A;
    int c=0;
    while(curr != NULL){
        c++;
        curr = curr->next;
    }
    if(c==1 || c==2) return A;
    curr = A;
    int mid = c/2-1;    // see the jumps, not the position
    while(mid--){
        curr = curr->next;
    }
    ListNode* headR = curr->next;
    if(c%2 != 0){
        //curr = NULL;
    }
    else curr->next = NULL;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    
    // Reversing th 2nd half
    while(headR != NULL){
        next = headR->next;
        headR->next = prev;
        prev = headR;
        headR = next;
    }
    // prev is the head of reverse 2nd half
    // A is the head of first half
    // now I need to merge these two
    curr = A;
    headR = prev;
    
    ListNode* nextR = NULL;
    while(curr != NULL && headR != NULL){
        next = curr->next;
        nextR = headR->next;
        curr->next = headR;
        headR->next = next;
        headR = nextR;
        curr = next;
    }
    return A;
}
