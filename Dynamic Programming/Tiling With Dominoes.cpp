int Solution::solve(int n) {
    if(n%2 != 0) return 0;
    if(n == 2) return 3;
    int m = 1e9+7;

    int A[n+1];
    int B[n+1];
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    
    A[0] = 1, A[1] = 0, B[0] = 0, B[1] = 1;
    for(int i=2; i<=n; i++){
        A[i] = (A[i-2]%m + 2*B[i-1]%m)%m;
        B[i] = (A[i-1]%m + B[i-2]%m)%m;
    }
    return A[n]%m;
}

/*
VISUALISATION - ugh
An =  No. of ways to completely fill a 3 x n board. (We need to find this)
Bn =  No. of ways to fill a 3 x n board with top corner in last column not filled.
Cn =  No. of ways to fill a 3 x n board with bottom corner in last column not filled.

Bn = Cn, nth column ke respect mei values hain
*/