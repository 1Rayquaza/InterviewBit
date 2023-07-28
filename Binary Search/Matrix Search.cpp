int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n=A.size();
    int m=A[0].size();
    // Discussion
    int i=0, j=m-1;
    while(i>=0 && i<n && j>=0 && j<m){
        if(A[i][j]==B) return 1;
        else if(A[i][j]<B) i++; //row - neeche no. inc.
        else j--;   // column - left mei no. decr.
    }
    return 0;
}
        
    
    // My method
    // find row in O(N) then find column by binary search
    // int row;
    // for(int i=0; i<n; i++){
    //     if(B>=A[i][0] && B<=A[i][m-1]){
    //         row = i;
    //         break;
    //     }
    // }
    
    // // Normal Binary Search
    // int lo=0, hi=m-1;
    // while(hi - lo > 1){
    //     int mid = (hi+lo)/2;
    //     if(A[row][mid]<B){
    //         lo = mid+1;
    //     }
    //     else{
    //         hi = mid;
    //     }
    // }
    // if(A[row][lo]==B) return 1;
    // else if(A[row][hi]==B) return 1;
    // return 0;




    // vector<int> vR(m);  //last row, diff. columns
    // vector<int> vC(n);  //last column, diff. rows
    // for(int j=0; j<m; j++){
    //     vR[j]=A[n-1][j];
    // }
    // for(int i=0; i<n; i++){
    //     vC[i]=A[i][m-1];
    // }
    // Now we've the limits
    // lower_bound(A.begin(), A.end(), B);
    // int hor = lower_bound(vR.begin(), vR.end(), B) - vR.begin();
    // int ver = lower_bound(vC.begin(), vC.end(), B) - vC.begin();