int Solution::solve(vector<int> &A, int B) {
    // Atmost B zeroes
    // prefix/suffix sum doesn't work properly because we might find another window with same zeroes but more 1's
    // Sliding window approach
    int n=A.size();
    int s=0, e=0; //best_s=0;
    int c=0, len=0;
    for(int e=0; e<n; e++){
        if(A[e]==0){
            c++;
        }
        while(c>B){
            if(A[s]==0) c--;
            s++;
        }
        int curr_len = e-s+1;
        if(curr_len > len){
            len = curr_len;
        }
    }
    // Had we also been asked to print the indices of the sequence, we'll have one more variable called best_s and 
    // we'll keep updating best_s = s whenever line 17 condn. satisfies
    return len;
}
