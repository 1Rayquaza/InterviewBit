int max_func(int a, int b, int c){
    int x = a > b ? a : b; 
    return x > c ? x : c;
}

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n1=A.size(), n2=B.size(), n3=C.size();
    // sorted arrays
    // if 2 arrays were given, minimize the absolute difference, but here- with a twist
    // O(N^3) if we pick one element each and keep finding min. of max. but need better...
    int i = 0, j = 0, k = 0, ans = INT_MAX;
    while(i<n1 && j<n2 && k<n3) {
        int x = max_func(abs(A[i] - B[j]), abs(A[i] - C[k]), abs(C[k] - B[j]));
        ans = min(ans, x);
        // min. waale ko increment krenge, to go for less difference
        // Windowing strategy again hehe :P
        if(A[i] <= B[j] && A[i] <= C[k]) i++;
        else if(B[j] <= A[i] && B[j] <= C[k]) j++;
        else k++;
    }
    return ans;
}