int Solution::bulbs(vector<int> &A) {\
    // 0-off, 1-on, turn on all
    // state of those on the right changes
    int n = A.size();
    
    int ct = 0;
    bool flag = true;
    for(int i=0; i<n; i++){
        if(flag == true){
            if(A[i] == 0){
                ct++;
                flag = false;
            }
        }
        
        else{
            if(A[i] == 1){
                ct++; // it was actually 0, but switch change made it 1
                flag = true;
            }
        }
    }
    
    return ct;
}
