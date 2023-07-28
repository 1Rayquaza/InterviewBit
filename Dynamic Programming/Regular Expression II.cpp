vector<vector<int>> dp;

int solve(const string &A, const string &B, int n, int m){
    if(n == 0 && m == 0){
        return dp[n][m] = 1;
    }
    
    if(m == 0){  // A mei kuch char bache but B khtm
        return dp[n][m] = 0;
    }
    
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    
    if(n == 0){
        return dp[n][m] = (B[m-1] == '*' ? solve(A, B, n, m-2) : 0);
    }
    
    if((A[n-1] == B[m-1]) || (B[m-1] == '.')){
        return dp[n][m] = solve(A, B, n-1, m-1);
    }
    
    else if(B[m-1] == '*'){
        if(A[n-1] == B[m-2] || B[m-2] == '.'){
            return dp[n][m] = solve(A, B, n-1, m) || solve(A, B, n, m-2);
        }
        else return dp[n][m] = solve(A, B, n, m-2);
    }
    
    else{
        return dp[n][m] = 0;   // total mismatched-no help
    }
}

int Solution::isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    
    dp.clear();
    dp.resize(n+1, vector<int> (m+1, -1));
    
    return solve(A, B, n, m);
}


// abcbcd
// a.*c.*d
// baaaaaabaaaabaaaaababababbaab
// ..a*aa*a.aba*a*bab*  0


// ababbaabbbaaaaabbaaabbababababbababbababbbaabbabbabbaaaabaabbbbaaabaaaaaabbbbbbbab
// a*.a*b*b..b*b*...bbb*b*..bb*a*..b*b*a*..aa..b*aa*.ba*.a*a*.b.abab*a*bab*b*.b*.a*a*.a.a*.ba*.b*b..ba.a*.baa*.b*b*a*.ab*..bbb*a*bba*a*..aa*.
