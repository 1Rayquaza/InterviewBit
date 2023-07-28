int Solution::firstMissingPositive(vector<int> &A) {
    //O(N) !!!
    for(int i=0; i<A.size(); i++){
        if(A[i]<=0 || A[i]>A.size() || A[i]==A[A[i]-1]){
            continue;
        }
        else{
            swap(A[i], A[A[i]-1]);  // no. ko uske index pr le gye
            i--;    // ***** cause we brought an Unknown no. at this position so need to recheck >_<
        }
    }
    
    for(int i=0; i<A.size(); i++){
        if(A[i]!=i+1){
            return i+1; //we're returning i+1!!!
        }
    }
    return A.size()+1;
}