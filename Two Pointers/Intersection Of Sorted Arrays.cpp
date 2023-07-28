vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int m=A.size();
    int n=B.size();
    int i=0, j=0;
    vector<int> common;
    while(i<m && j<n){
        if(A[i]>B[j]){
            j++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else{
            common.push_back(A[i]);
            if(i==m && j==n) break;
            i++;
            j++;
        }
    }
    
    return common;
}
