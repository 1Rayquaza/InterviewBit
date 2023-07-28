int Solution::removeDuplicates(vector<int> &A) {
    int n=A.size();
    int i=0;
    for(int j=1; j<n; j++){
        if(A[i]!=A[j]){
            i++;
            A[i]=A[j];  //Note: You need to update the elements of array A by removing all the duplicates :)
        }
    }
    return i+1;
}
