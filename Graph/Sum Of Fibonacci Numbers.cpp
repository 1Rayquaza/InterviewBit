int Solution::fibsum(int A) {
    vector<int> fnum;
    for(int i=0; i<3; i++){
        fnum.push_back(i);
    }
    
    while(fnum[fnum.size()-1] <= A){
        fnum.push_back(fnum[fnum.size()-1] + fnum[fnum.size()-2]);
    }
    
    int ans = 0;
    int i = fnum.size()-1;
    while(A > 0){
        if(fnum[i] <= A){   // using repeatedly until it cannot be used
            A = A-fnum[i];
            ans++;
        }
        else{
            i--;   // otherwise gotta go lo
        }
    }
    
    return ans;
}
