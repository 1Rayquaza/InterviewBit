

// Logarithmic mehod - O(1)
int Solution::divide(int A, int B) {
    // O(1) !!
    // A/B = e^(lnA - lnB)
    
    if(A == 0) return 0;
    long long sign = (A < 0)^(B < 0);   // XOR : 1^1 = 0, 0^0 = 0
    if(B == 1) return A;
    
    A = (A == INT_MIN ? INT_MAX : abs(A));
    B = (B == INT_MIN ? INT_MAX : abs(B));
    
    long long int ans = exp(log(A) - log(B)) + 0.0000000001;
    // adding 0.0000000001 to compensate for the precision errors ! ******
    
    ans = (ans > INT_MAX) ? INT_MAX : ans;
    return ((sign == 0) ? ans : -ans);
}