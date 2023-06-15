ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL || A->next == NULL) return A;
    ListNode* ansCurr = NULL;
    ListNode* curr = A;
    ListNode* ans = NULL;
    int c=0;
    ListNode* prev = NULL;
    
    while(curr != NULL){
        int val = curr->val;
        prev = curr;    // data lost ko preserve krne ke liye
        c=0;
        while(curr != NULL && curr->val == val){
            c++;
            curr = curr->next;
        }
        if(c==1){
            if(ansCurr == NULL){
                ans = prev;
                ansCurr = prev;
            }
            else{
                ansCurr->next = prev;
                ansCurr = ansCurr->next;
            } 
        }
        else{
            continue;
        }
    }
    if(ansCurr == NULL) return NULL;
    ansCurr->next = NULL;
    return ans;
}

// vector<int> Solution::deleteDuplicates(vector<int> A) {
//     vector<int> ans;
//     int n = A.size();
//     int i=0;
//     while(i<n){
//         int d = A[i];
//         int c=0;
//         while(A[i]=d){
//             i++;
//             c++;
//         }
//         if(c==1) ans.push_back(d);
//         else continue;
//     }
// }


