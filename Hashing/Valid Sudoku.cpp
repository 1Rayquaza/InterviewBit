int Solution::isValidSudoku(const vector<string> &A) {
    int n=A.size();
    map<char, int> m;   // use map to check for repeatation
    
    // checking for valid rows
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]=='.') continue;
            else if(m[A[i][j]] == 1) return 0;
            else m[A[i][j]] = 1;
        }
        m.clear();  // har row ke liye check then clear then check for next
    }
    
    // checking for valid columns
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            if(A[i][j]=='.') continue;
            else if(m[A[i][j]] == 1) return 0;
            else m[A[i][j]] = 1;
        }
        m.clear();
    }
    
    // checking for valid boxes ***
    for(int i=0; i<n; i+=3){
        for (int j=0; j<n; j+=3) {
            for (int k=i; k<i+3; k++) {
                for (int l=j; l<j+3; l++) {
                    if(A[k][l]=='.') continue;
                    else if(m[A[k][l]] == 1) return 0;
                    else m[A[k][l]] = 1;
                }
            }
            m.clear();
        }
    }
    return 1;
}
