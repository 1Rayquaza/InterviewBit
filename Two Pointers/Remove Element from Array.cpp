int Solution::removeElement(vector<int> &A, int B) {
    int n=A.size();
    int i=-1;
    //slow and fast pointers - i remains in reqd. position until we need to make a swap to replace the B at ith index. 
    for(int j=0; j<n; j++){
        if(A[j]!=B){
            i++;
            swap(A[i], A[j]);
        }
    }
    return i+1;
}
