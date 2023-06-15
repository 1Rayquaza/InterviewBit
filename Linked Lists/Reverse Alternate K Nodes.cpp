// we need to reverse B nodes then skip B nodes, then reverse B nodes and so on...
// similar to k revrse but with gaps inbetween

ListNode* Solution::solve(ListNode* A, int B) {
    if(B==1) return A;
    int flag;
    ListNode* curr = A;
    int c=0;
    while(curr != NULL){
        c++;
        curr = curr->next;
    }
    int num = c/B;
    int i=1;
    curr = A;
    
    ListNode* prev = NULL;
    ListNode* ans = NULL;
    while(i <= num){
        if(i%2==0) flag=0;  
        else flag=1;    // reverse
        
        ListNode* next = NULL;
        ListNode* initialH = NULL;
        ListNode* end = NULL;
        
        int j=1;
        if(flag==0){
            while(j<=B){
                prev = curr;
                curr = curr->next;
                j++;
            }
        }
        
        else{
            end = prev;
            initialH = curr;
            while(j<=B){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                if(i==1 && j==B){
                    ans = prev;
                }
                j++;
            }
            initialH->next = next;
            if(end != NULL){        // draw diagram and see how we need to connect !!
                end->next = prev;
            }
        }
        
        i++; 
    }
    return ans;
}
