int Solution::solve(vector<int> &A, int B) {
    // sorted array, O(logN)
    // number of elements which are less than or equal to B
    // find position of B then return j-i+1 hehe
    int n=A.size();
    int lo=0, hi=n-1;
    while(hi - lo > 1){ // stick with this condn. but manipulate the updation terms acc. to ques.
        int mid = (lo+hi)/2;
        if(A[mid]<=B){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    if(A[hi]<=B) return hi+1;   // two numbers can be same toh latter one will be considered for equal to condn. 
    else if(A[lo]<=B) return lo+1;
    return 0;
}
