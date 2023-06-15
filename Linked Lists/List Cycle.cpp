ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    while(fast->next != NULL && fast->next->next != NULL){  // 2 jumps karane, so both check
        slow = slow->next;
        fast = fast->next->next;
        if(fast->next == NULL) return NULL;
        if(slow == fast){   // if they meet, it implies the presence of cycle, now how to find cycle beginning
            break;
        }
    }
    if(fast->next == NULL || fast->next->next == NULL){
        return NULL;
    }   // If fast pointer becomes NULL, it implies no cycle was there
    
    slow = A;
    // fast will remain same at the above position(meeting point)
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

/* 
X = Distance between the head(starting) to the loop starting point.
Y = Distance between the loop starting point and the first meeting point of both the pointers.
C = The distance of the loop
X = K * C – Y, where K is some positive constant.

Now if reset the slow pointer to the head(starting position) and move both fast and slow pointer by one unit
at a time, both of them will meet after travelling X distance at the meeting point     
*/