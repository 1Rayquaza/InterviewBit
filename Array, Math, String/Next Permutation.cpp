vector<int> Solution::nextPermutation(vector<int> &A) {
    //write down and observe
    int n=A.size();
    
    // vector<int> suffix; //go with index, simpler
    int id1 = -1, id2 = -1;
    for(int i=n-2; i>=0; i--){
        if(A[i]<A[i+1]){
            id1 = i;
            break;  //we get the point of change, after and including which we need to perform the changes
        }
    }
    
    if(id1==-1){
        reverse(A.begin(), A.end());
        return A;
    }
    
    //find the element for exchange
    for(int j=n-1; j>id1; j--){
        if(A[j]>A[id1]){
            id2 = j;
            break;
        }
    }
    
    //now we need to swap these and reverse the rest for the next nextPermutation
    swap(A[id1], A[id2]);
    reverse( (A.begin()+id1+1), A.end());
    return A;
    
}

