int Solution::candy(vector<int> &A) {
    int n = A.size();
    
    // Each child must have at least one candy, now increment as per need
    vector<int> left(n, 1);
    vector<int> right(n, 1);
   
    for(int i=1; i<n; i++) {
        if(A[i] > A[i-1]) {
            left[i] = left[i-1] + 1;
        }
    }
   
    for(int i=n-2; i>=0; i--) {
        if(A[i] > A[i+1]) {
            right[i] = right[i+1] + 1;
        }
    }
   
    int sum = 0;
    for(int i=0; i<n; i++) {
        left[i] = max(left[i], right[i]);
        sum += left[i];
    }
   
    return sum;
    
}

//  ith children should have more candies than the (i-1)th and (i+1)th children if -
//  one of them has lesser rating from the ith children.
// if ratings:- 1 2 2 2 1
//    candies:- 1 2 1 2 1   // middle 2 has neighbours 2,2: neither is < so no extra candies, infact, -1
