int dp[101][10001];

int egg(int e, int f){
    if(e == 1) return f;
    if(f == 0 || f == 1) return f;
    
    if(dp[e][f] != -1){
        return dp[e][f];
    }
    
    int mn = INT_MAX;
    int lo = 1, hi = f-1;
    while(hi - lo > 1){
        int mid = (lo+hi)/2;
        int left = egg(e-1, mid-1);  // egg_break
        int right = egg(e, f-mid);   // egg_safe
        // mid-1 -> inc. ; f-mid ->decr. ; max. of this is top half graph, then find min
        
        if(left < right){   // draw graphs for simple understanding
            lo = mid;
        }
        else if(left > right){
            hi = mid-1;
        }
        else{
            lo = mid;
            hi = mid;
        }
    }
    
    int tmplo = 1 + max(egg(e-1, lo-1), egg(e, f-lo));  // +1 for current floor f
    int tmphi = 1 + max(egg(e-1, hi-1), egg(e, f-hi));
    mn = min(tmplo, tmphi);
    return dp[e][f] = mn;
}

int Solution::solve(int e, int f) {
    memset(dp, -1, sizeof(dp));
    if(e == 1) return f;
    if(f == 0 || f == 1) return f;
    return egg(e, f);
}
