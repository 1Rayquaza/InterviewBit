vector<int> Solution::solve(vector<int> &A) {
    // int n = A.size();
    // int c=0;
    
    // vector<int> R;   //EXTRA SPACE
    // for(int i=0; i<n; i++){
    //     if(A[i] != 0){
    //         R.push_back(A[i]);
    //     }
    //     else{
    //         c++;
    //     }
    // }
    
    // for(int i=0; i<c; i++){
    //     R.push_back(0);
    // }
    // return R;
    
    int i=0, j=0;
    for(i; i<A.size(); i++){
        if(A[i]!=0){     //All the non-zero elements must retain their original order so usko pehle le aate,
            A[j] = A[i]; //zero's apne aap last mei ho jayenge
            j++;         //jahan non-zero no.s mile @i posn. pr, usko pehle krdo, end mei saarei bache zeroes ko print krdo
        }
    }
    for(j; j<A.size(); j++){   
        A[j]=0;
    }
    return A;
}