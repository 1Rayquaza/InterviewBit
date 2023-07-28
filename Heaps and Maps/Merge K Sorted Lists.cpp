#define pi pair<int, ListNode*>

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int n = A.size(); // vector contains heads of n lists
    priority_queue<pi, vector<pi>, greater<pi>> minH;
    // min. element on top for easy access
    for(int i=0; i<n; i++){
        minH.push({A[i]->val, A[i]});  // need the values to compare, and nodes to traverse
        /* contains heads of all, now next element after updation will automatically take it's place in a
        sorted manner hence top will always be minimum yayyy */
    }
    
    // our min heap contains head of all, basically all elements
    ListNode* ans = NULL;
    ListNode* ansCurr = NULL;
    
    while(minH.size() != 0){
        ListNode* t = minH.top().second;
        minH.pop();
        
        if(ans == NULL){
            ans = t;
            ansCurr = t;
        }    
        else{
            ansCurr->next = t;
            ansCurr = ansCurr->next;
        }
        
        if(t->next){    // t is the node
            minH.push({t->next->val, t->next});  // we need to push a pair of value and node
        }
    }
    ansCurr->next = NULL;
    return ans;
}
