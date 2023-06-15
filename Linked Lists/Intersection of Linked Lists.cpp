ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode* curr1 = A;
    ListNode* curr2 = B;
    int c1=0, c2=0;
    while(curr1 != NULL){
        c1++;
        curr1 = curr1->next;
    }
    while(curr2 != NULL){
        c2++;
        curr2 = curr2->next;
    }
    
    // both should be equidistant from the intersection pt, so reducing the length of longer list
    int d = abs(c1-c2);
    curr1 = A;
    curr2 = B;
    
    if(c1>c2){
        while(d--){
            curr1 = curr1->next;
        }
    }
    else{
        while(d--){
            curr2 = curr2->next;
        }
    }
    
    while(curr1 != NULL && curr2 != NULL && curr1 != curr2){
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if(curr1 == NULL || curr2 == NULL) return NULL;
    return curr1;
}
