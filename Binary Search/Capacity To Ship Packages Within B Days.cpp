bool isPossible(vector<int> &A, int B, int mid){    // mid being the weight of ship
    int n=A.size();
    int wt=0;
    int d=1;
    for(int i=0; i<n; i++){
        wt+=A[i];
        if(wt > mid){
            d++;
            wt=A[i];
            // (commented after above edit) i--;    //'cause this wt didn't add
        }
    }
    return d<=B;
}

int Solution::solve(vector<int> &A, int B) {
    // sorta like wood cutting problem
    int n=A.size();
    // the cargo must be shipped in the order given, array may NOT be sorted(doesn't matter tho)
    int mx = 0, sum = 0;
    for(int i=0; i<n; i++){
        sum += A[i];
        mx = max(mx, A[i]);
    }
    if(B == n) return mx;
    if(B == 1) return sum;

    int lo=mx, hi=sum; //weight capacity
    while(hi - lo > 1){
        int mid = (lo+hi)/2;
        // assuming there's a fn. that allows us to know whether condn. is possible or not, let's write further
        // FFF..FTTT..T, pehla T dhoond kr return krna hai
       if(isPossible(A, B, mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    if(isPossible(A, B, lo)) return lo;
    else return hi;
}
