// TC: O(N) and SC: O(1) - Boyer-Moore Majority Voting Algorithm
int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    // there can only be 2 elements whose ct is greater than 3
    int c1, c2;
    int ct1 = 0, ct2 = 0;
    
    for(int i=0; i<n; i++){
        if(c1 == A[i]) ct1++;
        else if(c2 == A[i]) ct2++;
        
        else if(ct1 == 0){
            c1 = A[i];
            ct1++;
        }
        
        else if(ct2 == 0){
            c2 = A[i];
            ct2++;
        }
        
        else{
            ct1--;
            ct2--;
        }
    }
    
    ct1 = 0, ct2 = 0;
    for(int i=0; i<n; i++){
        if(A[i] == c1)  ct1++;
        else if(A[i] == c2) ct2++;
    }
    
    if(ct1 > n/3) return c1;
    else if(ct2 > n/3)  return c2;
    else return -1;
}