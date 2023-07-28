long long multiply(long mid, int n){
    long long ans = 1;
    for(int i=0; i<n; i++){
        ans *= mid;
    }
    return ans;
}

int Solution::sqrt(int A) {
    // using Binary search to reduce TC
    if(A <= 0) return 0;
    if(A == 1) return 1;
    long long lo=1, hi=A;
    int n=2;
    // double eps = 1e-2; for precision
    while(hi - lo > 1){
        long long mid = (lo+hi)/2;
        // let say there's a power fn. which tells us if the power lies to left or right of mid
        // T for left side, F for right side
        if(multiply(mid, n) < A){   //for nth root, here n=2
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    // if(multiply(lo, n) <= A) return lo;
    // else return hi;
    if(multiply(lo, n)==A) return lo;
    else if(multiply(hi, n)==A) return hi;
    else if(multiply(lo, n)>A) return lo;
    else if(multiply(hi, n)<A) return hi;
    else return lo;
}
