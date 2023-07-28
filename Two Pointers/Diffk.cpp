int Solution::diffPossible(vector<int> &A, int B) {
    int n=A.size();
    if(n<2) return 0;
    
    int l=0, r=1;
    while(l<r && r<n){
        int d=(A[r]-A[l]);
        if(d==B) return 1;

        else if(d>B){
            l++;
            if(r==l){
            r++; 
            }
        } 
        else{
            r++;
        }
    }
    return 0;
}


// A : [ 2, 14, 18, 23, 25, 36, 40, 44, 44, 53, 54, 68, 71, 80, 94 ]
// B : 82