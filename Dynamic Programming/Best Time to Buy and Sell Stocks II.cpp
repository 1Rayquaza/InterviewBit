int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    int profit = 0;
    for(int i=0; i<n-1; i++){
        if(A[i+1] > A[i]){
            profit += (A[i+1]-A[i]);
        }
    }    
    return profit;
}
