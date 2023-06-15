/*
    1 -> 2 -> 3 -> 4 -> NULL
    prev curr next  // next = curr->next
     2(connected to 3)     
1 -> 3 -> 4 -> NULL  // prev->next = next    // odd no.s connected
1 -> 3 -> 4`-> NULL  // curr->next = next->next i.e. 4 connected to 2  
          2(connected to 4)
*/

// Always draw neat diagrams clearly!

ListNode* Solution::solve(ListNode* A) {
    ListNode* curr = A->next;   // even elements to be separated
    ListNode* currE = A->next;  
    ListNode* next = NULL;
    ListNode* prev = A; 
    while(curr != NULL && curr->next != NULL){  // curr->next->next != NULL this condn. NO 'cause odd ko bhi connectr krna
        next = curr->next;    
        prev->next = next;  // previous to current element, connect to prior odd no.
        // both above are odd and needs to be connected
        if(next->next == NULL){
            curr->next = NULL;
        }
        else{
            curr->next = next->next; // even no. connected    
        }
        curr = curr->next; // to the next even no. // upar ek baar update ho gya already so only one jump
        prev = next;
    }
    prev->next=NULL;      // The COMMENT!!!! else link break nhi hogit odd-even waali and infinite loop chalega
    
    curr = A;   // odd ka head
    // currE is starting of even list which needs to be reversed
    
    next = NULL;
    prev = NULL;
    while(currE != NULL){
        next = currE->next;
        currE->next = prev;
        
        prev = currE;
        currE = next;
    }
    currE = prev;
    //cout<<currE->val<<endl;
    
    // now we got the reversed even list, just need to merge the two
    ListNode* nextE = NULL;
    while(curr != NULL && currE != NULL){
        next = curr->next;
        nextE = currE->next;
        curr->next = currE;
        currE->next = next;
        currE = nextE;
        curr = next;
    }
    
    return A;
}
