// Actually we only need to break once and join once, rest will fall into place
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A == NULL) return NULL;
    if(A->next == NULL) return A;
    ListNode* curr = A;
    int c=0;
    while(curr->next != NULL){
        c++;
        curr = curr->next;
    }
    B = B%(c+1);
    if(B==0) return A;
    curr->next = A; // end joined to first, ab pehle ka todna
    int k = c-B;
    curr = curr->next;  // i.e. A
    while(k--){
        curr = curr->next;  // reaching the breaking pt.
    }
    
    ListNode* h = curr->next;
    curr->next = NULL;
    return h;   
}