int Solution::removeDuplicates(vector<int> &A) {
    //Return the new length, but make sure to change the original array as well in place
    //O(N)
    //count < 3
    int n=A.size();
    if(n==1) return 1;
    int i=0;
    int flag=1; //set the flag for every new element and once the element is added twice (for duplicates),
                //we set the flag back to false not adding further duplicates.
    for(int j=0; j<n-1; j++){
        if(A[j]!= A[j+1]){
            A[i]=A[j];  //jbb equal hona band ho jaaye tbb last duplicate ko slow pointer mei daal do
            i++;
            flag=1;
        }
        else if(A[j] == A[j+1] && flag==1){
            A[i]=A[j];
            i++;
            flag=0;
        }
    }
    A[i] = A[n-1];
    i++;
    return i;
}