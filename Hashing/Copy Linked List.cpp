RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* curr = A;
    // Try to think how you can maintain link between old nodes and new nodes.
    // ditto copy without using anything from original list
    RandomListNode* prev = NULL;
    RandomListNode* hNew = NULL;
    while(curr != NULL){
        int val = curr->label;
        RandomListNode* temp = new RandomListNode(val);
        if(hNew == NULL){
            hNew = temp;
        }
        if(prev != NULL){
            prev->next = temp;
        }
        prev = temp;
        curr = curr->next;
    }
    
    /* original node ke corresponding copy ko store krayenge, call krne pr uske corresponding same 
    valued node(but different node) */
    unordered_map<RandomListNode*, RandomListNode*> m;
    curr = A;
    RandomListNode* temp = hNew;
    
    while(curr != NULL){
        m[curr] = temp; //poorani list ke pointer ke corresponding new pointer with same value store ho rha 
        curr = curr->next;
        temp = temp->next;
    }
    
    curr = A;
    RandomListNode* hC = hNew;
    while(curr != NULL){
        hC->random = m[curr->random];
        hC = hC->next;
        curr = curr->next;
    }
    
    return hNew;
}
