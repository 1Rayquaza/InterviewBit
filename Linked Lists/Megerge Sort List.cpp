// ans and ansCurr waala approach is BESTTT !!! 
ListNode* merge(ListNode* A, ListNode* B){
    if(A == NULL) return B;
    if(B == NULL) return A;
    
    ListNode* currA = A;
    ListNode* currB = B;
    ListNode* ans = NULL;
    ListNode* ansCurr = NULL;
    
    while(currA != NULL && currB != NULL){
        if(currA->val < currB->val){
            if(ans == NULL){
                ans = currA;
                ansCurr = currA;
            }
            else{
                ansCurr->next = currA;
                ansCurr = ansCurr->next;
            }
            currA = currA->next;
        }
        else{
            if(ans == NULL){
                ans = currB;
                ansCurr = currB;
            }
            else{
                ansCurr->next = currB;
                ansCurr = ansCurr->next;
            }
            currB = currB->next;
        }
    }
    
    if(currA != NULL) ansCurr->next = currA;
    else ansCurr->next = currB;
    
    return ans;
}

ListNode* Solution::sortList(ListNode* A) {
    ListNode* curr = A;
    int c=0;
    
    while(curr != NULL){
        c++;
        curr = curr->next;
    }

    if(c==0) return NULL;
    if(c==1) return A;
    
    int m = (c-1)/2;  // mid = jumps reqd.
    ListNode* mid = A;
    while(m--){
        mid = mid->next;
    }
    // now mid points to end of left half till where we'll sort
    
    ListNode* B = mid->next;
    mid->next = NULL;
    
    A = sortList(A);
    B = sortList(B);
    
    return merge(A, B);
}
