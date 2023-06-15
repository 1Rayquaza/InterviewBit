ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* curr = A;
    int c=0;
    while(curr != NULL){
        c++;
        curr = curr->next;
    }
    
    if(c<=B){
        return A->next;
    }
    // make diagrams and it will be clear, already first element pr hain toh ek km move krna
    // see the jumps, not the position
    int d = c-B-1;  
    if(d==0) return A->next;
    //cout << d << endl;
    curr = A;
    while(d-- && curr != NULL){ // !=NULL st last waala remove krna ho toh issue nhi aaye
        curr = curr->next;
    }
    curr->next = curr->next->next;
    
    return A;
}
