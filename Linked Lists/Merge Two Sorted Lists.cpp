ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A == NULL) return B;
    if(B == NULL) return A;
    
    ListNode* currA = A;
    ListNode* currB = B;
    ListNode* ans = NULL;
    ListNode* ansCurr = NULL;
    // ans and ansCurr is the best approach since it removes the ambiguity faced in prev and next
    
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
    if(currA != NULL){
        ansCurr->next = currA;
        currA = currA->next;
    }
    else if(currB != NULL){
        ansCurr->next = currB;
        currB = currB->next;
    }
    return ans;
}