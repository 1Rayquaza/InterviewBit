int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int j=0, c=0, sum=0;
    for(int i=0; i<n; i++){
        sum+=A[i];
        while(sum>=B){
            sum-=A[j];
            j++;
        }
        c = c+(i-j+1);  //jitni baar j increment hua utna subtract ho jayega
    }
    return c;
}


// upto 0(N2) alllowed
    // subarray sum and compare
    // int n=A.size();
    // int i=0;
    // int sum=0, c=0;
    // while(i<n){
    //     for(int j=i; j<n; j++){
    //         sum+=A[j];
    //         if(sum<B) c++;
    //     }
    //     i++;
    //     sum=0;
    // }
    // return c;
//can be optimized more... because we're calculating the sum again and again
// Sliding window