// Read questions properly, digits are already in REVERSE order !! ufff
// Supposedly A >= B in length, will account by finding length

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(A == NULL) return B;
    if(B == NULL) return A;
    ListNode* i = A;
    ListNode* j = B;
    
    int l1=0, l2=0;
    while(i != NULL){
        l1++;
        i = i->next;
    }
    while(j != NULL){
        l2++;
        j = j->next;
    }
    
    // making i corresponding to larger number in order to work with that later
    if(l1 <= l2){
        i = B;
        j = A;
    }
    else{
        i = A;
        j = B;
    }
    
    int c = 0;
    while(i != NULL && j != NULL){
        int d = i->val + j->val + c;
        if(d <= 9){
            i->val = d;
            c = 0;
        }
        else{
            i->val = d%10;
            c = 1;
        }
        i = i->next;
        j = j->next;
    }
    
    ListNode* prev;
    while(i != NULL){
        int d = i->val + c;
        if(d <= 9){
            i->val = d;
            c = 0;
        }
        else{
            i->val = d-10;
            c = 1;
        }
        if(i->next == NULL){
            prev = i;
        }
        i = i->next;
    }
    
    ListNode* tmp = new ListNode(1);
    if(c==1){
        prev->next = tmp;
    }
    ListNode* ans;
    if(l1 <= l2) ans = B;
    else ans = A;
    
    // to remove trailing zeroes
    ListNode* curr = ans;
    ListNode* check = NULL;
    int flag = 0;
    while(curr->next != NULL){
        if(curr->next->val == 0 && flag == 0){
            check = curr;
            flag = 1;
        }
        else{
            check = NULL;
            flag = 0;
        }
        curr = curr->next;
    }
    
    // for checking last element
    if(curr->val == 0 && flag == 0){
        check = curr;
        flag = 1;
    }
    else{
        check = NULL;
        flag = 0;
    }
        
    if(check != NULL){
        check->next = NULL;
    }
    return ans;
}