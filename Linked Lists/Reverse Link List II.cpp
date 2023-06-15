ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B==C) return A;
    ListNode* curr = A;
    ListNode* connect = NULL;
    int i=1;
    while(i<B-1){
        curr = curr->next;
        i++;
    }
    connect = curr;    // to store info for connecting to reversed sub-list
    if(B!=1) curr = curr->next; // to account for B=1 then curr starting mei hi rhega 
    ListNode* head = curr;
    int d = C-B+1;
    
    //cout << connect->val << " " << curr->val << " " << head->val << " " << d << " " << "okay" << endl;
    
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while(d--){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if(B==1){
        head->next = curr;
        return prev;
    }
    connect->next = prev;
    head->next = curr;
    return A;
}
