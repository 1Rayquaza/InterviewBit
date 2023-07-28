bool isSafe(vector<string> &tmp, int row, int col, int n){
    // we need to check placement of queens and only one can be there in a row, check col only
    for(int j=0; j<=row; j++){ 
        if(tmp[j][col] == 'Q') return false;
    }
    
    // diagonal check ?
    int r = row;
    int c = col;
    // since we're building from bottom up, we only need to check the previous rows
    while(r>=0 && c>=0){
        if(tmp[r][c] == 'Q') return false;
        r--;
        c--;
    }
    
    r=row;
    c=col;
    while(r>=0 && c<tmp.size()){
        if(tmp[r][c] == 'Q') return false;
        r--;
        c++;
    }
    
    return true;
}

void generate(vector<vector<string> > &ans, vector<string> &tmp, int row, int n){
    if(row == n){
        ans.push_back(tmp);
        return;
    }
    for(int j=0; j<n; j++){
    // we need to check placement of queens and only one can be there in one row, so only one loop reqd.
        if(isSafe(tmp, row, j, n)){
            tmp[row][j] = 'Q';
            generate(ans, tmp, row+1, n);
            tmp[row][j] = '.';  // UFFFFFFFFFFF, backtrack !!!! =_=
        }
    }
    
}

vector<vector<string> > Solution::solveNQueens(int A) {
    int n=A;
    vector<vector<string> > ans;
    vector<string> tmp(A);
    string t;
    for(int i=0; i<A; i++){
        t.push_back('.');
    }
    for(int i=0; i<A; i++){
        tmp[i] = t;
    }
    // now we've got the grid with dots(empty positions and need to fill it like sudoku)
    
    generate(ans, tmp, 0, n);
    return ans;
}

/* Diagonal Sudoku problem 
similar to sudoku problem, just with 1 digit to be placed n times like any num placed 9 times in 9*9 grid
We need to place A queens, when A becomes 0(means all queens were put up safely) then push to ans */
