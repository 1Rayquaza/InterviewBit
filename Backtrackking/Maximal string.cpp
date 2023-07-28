void generate(string &A, int B, int n, string &mx){
    if(B == 0){
        return;
    }
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(A[i], A[j]);
            B--;
            mx = max(mx, A);
            
            generate(A, B, n, mx);  // swapping in A, but storing max in mx
            swap(A[i], A[j]);
            B++;    // backtrack to original string before the amendment, and +1 swap
        }
    }
}

string Solution::solve(string A, int B) {
    int n=A.size();
    string mx = A;
    generate(A, B, n, mx);
    return mx;
}


/* for the maximal lexicographical string, we'll need the max. digit in the leftmost place, 
then traverse the remaining string ang again bring the max digit to left 
1. Make things smaller from left, swap with max ele, push in ans string, erase first, repeat

Facing an ISSUE: What if a max integer is already in middleway ? I need to skip that posn. 
and find max from the end, and skip (max)digits in the beginning */