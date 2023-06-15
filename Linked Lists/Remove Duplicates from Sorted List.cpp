// When in doubt, apprach with vectors then convert
// In an array, we'd accept the first one, then move to next, if it's equal then erase and move to next
// here, change address to next 
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL || A->next == NULL) return A;
    
    ListNode* i = A;
    ListNode* j = A->next;
    
    while(j != NULL){
        if(i->val != j->val){
            i = i->next;
            i->val = j->val;
        }
        j = j->next;
    }
    
    i->next = NULL;
    return A;
}

    // int i=0;
    // for(int j=1; j<n; j++){
    //     if(A[i]!=A[j]){
    //         i++;
    //         A[i]=A[j];  //Note: You need to update the elements of array A by removing all the duplicates :)
    //     }
    // }
    // return i+1;


