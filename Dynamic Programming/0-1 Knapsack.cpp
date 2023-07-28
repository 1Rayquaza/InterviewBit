// Approach 2: Memoization 
int static t[1001][1001];
// Initialisation yahan ho jaata hai but value set main fn. mei krna hota hai
int mx(vector<int> &val, vector<int> &wt, int C, int n){
    if(n == 0 || C == 0) return 0;
    
    if(t[n][C] != -1){
        return t[n][C];
    }
    if(wt[n-1] <= C){
        return t[n][C] = max( (val[n-1] + mx(val, wt, C-wt[n-1], n-1)), mx(val, wt, C, n-1) );
    }
    else return t[n][C] = mx(val, wt, C, n-1);
}   

int Solution::solve(vector<int> &val, vector<int> &wt, int C) {
    memset(t, -1, sizeof(t));
    int n = val.size();
    return mx(val, wt, C, n);
}


// Approach 3: Top Down Approach DP
int Solution::solve(vector<int> &val, vector<int> &wt, int w) {
    int n = val.size();
    int t[n+1][w+1];
    
    // Initialisation aka Base condition 
    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            if(i==0 || j==0) t[i][j] = 0;
        }
    }
    
    // n,w -> i,j from the recursive fn.
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1] <= j){
                t[i][j] = max( (val[i-1] + t[i-1][j-wt[i-1]]), t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][w];
}

// Approach 1: Recursion
int mx(vector<int> &val, vector<int> &wt, int C, int n){
    if(n == 0 || C == 0) return 0;
    
    if(wt[n-1] <= C){
        return max( (val[n-1] + mx(val, wt, C-wt[n-1], n-1)), mx(val, wt, C, n-1) );
    }
    
    else return mx(val, wt, C, n-1);
    
}   

int Solution::solve(vector<int> &val, vector<int> &wt, int C) {
    int n = val.size();
    return mx(val, wt, C, n);
}



