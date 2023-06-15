int Solution::solve(ListNode* A, int B) {
    ListNode* curr = A;
    if(A->next == NULL) return -1;
    
    int c=0;
    while(curr != NULL){
        c++;
        curr = curr->next;
    }
    
    // see the jumps, not the position
    int mid = c/2 + 1;
    if(B >= mid) return -1;
    
    B = mid-B-1;
    curr = A;
    while(B>0){
        curr = curr->next;
        B--;
    }
    return curr->val;
}
