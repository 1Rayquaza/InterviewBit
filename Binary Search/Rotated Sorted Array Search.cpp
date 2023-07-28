int Solution::search(const vector<int> &A, int B) {
    /* sequence: first strictly increasing then after a point decreasing once, then strictly increasing
    Predicate fn., have to find the last peak before dip /|/  Need to do this in O(logN) */
    // Right region elements will Always be smaller than every element of Left region ***
    int n = A.size();
    int lo=0, hi=n-1;
    while(hi - lo > 1){
        int mid = (lo + hi)/2;
        // int l = A[mid-1], r = A[mid+1];
        if(A[mid] >= A[0]){   // Left region
            lo = mid;
        }
        else if(A[mid] < A[0]){
            hi = mid;
        }
    }
    // lo would be pivot, hi would be that zero indexed element, whatever, both are inc. fn. so apply 
    // BS safely and find B in O(logN)
    // cout << A[lo] << " " << A[hi] << endl;
    int l=0, h=lo;
    while(h - l > 1){
        int mid = (l+h)/2;
        if(A[mid] < B){
            l = mid+1;
        }
        else{
            h = mid;
        }
    }
    if(A[l]==B) return l;
    else if(A[h]==B) return h;
    
    l=lo+1, h=n-1;
    while(h - l > 1){
        int mid = (l + h)/2;
        if(A[mid] < B){
            l = mid+1;
        }
        else{
            h = mid;
        }
    }
    if(A[l]==B) return l;
    else if(A[h]==B) return h;
    
    return -1;
}
