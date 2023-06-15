ListNode* Solution::reverseList(ListNode* A, int B) {
    
    if(A==NULL) return NULL;
    if(B==0 || B==1) return A;  // Base Condition
    
    ListNode* prev = NULL;   
    ListNode* curr = A; // this keeps changing dw :)
    ListNode* next = NULL;
    
    int c=0;
    while(c<B){ // ek B size ke bucket ko reverse krliya
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    
    if(next != NULL){
        A->next = reverseList(curr, B);   // next mei agla reversed add hojayega
    }
    return prev;
}