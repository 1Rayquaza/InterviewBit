int countLeft(int x, vector<vector<int> > &A){
    int r=A.size();
    int ct=0;
    for(int i=0; i<r; i++){ //careful about r/c as upperbound apne aap poora row traverse kr lega
        ct += (upper_bound(A[i].begin(), A[i].end(), x) - A[i].begin()); // vector of vectors se dekho, A[0], A[i], ... like usual
    }
    return ct;
}

bool isPresent(int x, vector<vector<int>> &A){
    int r = A.size(), c = A[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(A[i][j]==x)
                return true;
        }
    }
    return false;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    // Brute force - two for loops, sort then middle element but constraints will help to reduxce TC
    // rows are sorted, N*M<=10e6 i.e. upto O(N*M) allowed
    // in a row you can binary search to find how many elements are smaller than a value X in O(log M)
    // N*M is odd, only one median directly
    // Median - find (n/2 + 1)th element in sorted array i.e., a no. which is greater than n/2 elements in the array
    int k = (row*col+1)/2;
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i=0; i<row; i++){
        mx = max(mx, A[i][col-1]);
        mn = min(mn, A[i][0]);
    }
    
    int lo = mn, hi = mx;
    while(hi - lo > 1){
        int mid = (lo+hi)/2;
        // let's say we've got a fn. that gives us count of no. less than this mid
        int c = countLeft(mid, A);
        if(c >= k){  //careful ***********
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    if((countLeft(lo, A) >= k) && (isPresent(lo, A))) return lo;
    else return hi;
}


    


