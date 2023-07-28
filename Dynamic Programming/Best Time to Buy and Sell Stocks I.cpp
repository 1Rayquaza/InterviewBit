int Solution::maxProfit(const vector<int> &A) {
    int n=A.size();
    // return profit(A, n);
    int mx = INT_MIN;
    int tmp;
    for(int i=n-1; i>=0; i--){
        mx = max(mx, A[i]); 
        tmp = max(tmp, (mx-A[i]));
    }
    return tmp;
}
