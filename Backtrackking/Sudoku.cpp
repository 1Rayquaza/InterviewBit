// we need to check if the number considered has not appeared in THAT PARTICULAR row/column/cell
bool isSafe(vector<vector<char> > &A, int row, int col, char candidate){
    for(int i=0; i<9; i++){ 
        if(A[i][col] == candidate) return 0;
        if(A[row][i] == candidate) return 0;
    }
    
    // I only need to identify the starting indices
    int r = row - row%3;
    int c = col - col%3;
    for(int i=r; i<r+3; i++){
        for(int j=c; j<c+3; j++){
            if(A[i][j] == candidate) return 0;
        }
    }
        
    return true;    
}

bool isComplete(vector<vector<char> > &A, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] == '.') return false;
        }
    }
    return true;
}

bool generate(vector<vector<char> > &A, int n, vector<vector<char> > &ans){
    // we need to generate sudokus and see when it return true(Solution)
    // we'll fill the no. which is not there, like Permutations ques.
    if(isComplete(A, n)){
        ans = A;
        return true;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] == '.'){
                for(char c='1'; c<='9'; c++){
                    if(isSafe(A, i, j, c)){ // for row i, loop over j; for column j, loop over i
                        A[i][j] = c;
                        // generate(A, n, ans); // ab A mei ye value bhi update hogyi
                        if(generate(A, n, ans)) return true;
                        A[i][j] = '.';
                    }
                }
                return false;   // . as it is, no char safe
            }
        }
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    int n = A.size();
    vector<vector<char> > ans;
    generate(A, n, ans);
    A = ans;
}

// we need to UPDATE the given A but anyway, let's do with extra space or whatever