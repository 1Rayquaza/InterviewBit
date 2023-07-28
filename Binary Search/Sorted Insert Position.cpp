int Solution::searchInsert(vector<int> &A, int B) {
    int n=A.size();
    // lower_bound(B) but optimize it more sooo... Binary Search :D
    int lo=0, hi=n-1;
    while(hi - lo > 1){
        int mid = (lo+hi)/2;
        if(A[mid]<B){
            lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    
    // Consider all cases and possible answers for each case on paper ezz.
    if(A[lo]==B) return lo;
    else if(A[hi]==B) return hi;
    else if(A[hi]<B) return hi+1;
    else if(A[lo]>B){
        if(lo==0) return 0;
        return lo;
    }
    else return hi;
}
