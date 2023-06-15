ListNode* Solution::solve(ListNode* A) {
    ListNode* i = A;
    ListNode* j = A;
    while( i != NULL && j != NULL){
        if(j->val == 0){
            swap(i->val, j->val);
            i = i->next;
            j = j->next;
        }
        else{
            j = j->next;
        }
    }
    return A;
}

// i will move only when new element is added, j will traverse all