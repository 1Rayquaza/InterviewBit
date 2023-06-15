// Listen... only the values needs to be sorted, pointers will stay the same
// kinda like sorting question, need two pointers
// one pointer will traverse the list one by one, 2nd will take care of no.s. less than B
// Realative order shall remain the same !!
ListNode* Solution::partition(ListNode* A, int B) {
    
    ListNode* lo = NULL;
    ListNode* hi = NULL;
    ListNode* hlo = NULL;
    ListNode* hhi = NULL;
    ListNode* curr = A;
    
    while(curr != NULL){
        if(curr->val < B){
            if(lo == NULL){
                hlo = curr;
                lo = curr;
            }
            else{
                lo->next = curr;
                lo = lo->next;
            }
            
        }
        else{
            if(hi == NULL){
                hhi = curr;
                hi = curr;
            }
            else{
                hi->next = curr;
                hi = hi->next;
            }
        }
        curr = curr->next;
    }
    
    hi->next = NULL;    // end mei NULL bhi point kraana h else infinite loop
    if(lo==NULL) return hhi;

    lo->next = hhi;
    return hlo;
}

