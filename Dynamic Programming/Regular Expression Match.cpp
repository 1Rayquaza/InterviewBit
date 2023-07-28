int Solution::isMatch(const string s, const string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
    // return match(s, p, m, n, dp);  
    
    dp[0][0] = 1;
    
    for(int i=1; i<=m; i++){
        dp[i][0] = 0;
    }
        
    for(int j=1; j<=n; j++){
        if(p[j-1] != '*'){
            dp[0][j] = 0;
        }
        else{
            dp[0][j] = dp[0][j-1];
        }
    }
        
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if((s[i-1] == p[j-1]) || (p[j-1] == '?')){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[m][n]; 
}

// bool match(const string &A, const string &B, int m, int n, vector<vector<int>> &dp){    
//     if(m==0 && n==0){
//         return 1;
//     }
//     if(n == 0){ // A mei kuch char bache hain but B khtm, no match
//         return 0;
//     }
    
//     if(dp[m][n] != -1){
//         return dp[m][n];
//     }
    
//     if(m == 0){
//         while(n > 0){
//             if(B[n-1] != '*'){
//                 return 0;
//             }
//             n--;
//         }
//         return 1;
//     }
    
//     if((A[m-1] == B[n-1]) || (B[n-1] == '?')){
//         return dp[m][n] = match(A, B, m-1, n-1, dp);
//     }
    
//     else if(B[n-1] == '*'){
//         return dp[m][n] = ((match(A, B, m-1, n, dp)) || match(A, B, m, n-1, dp));
//         // ((match(A, B, m-1, n-1)  * once/multiple use ke liye same condn. as == waala aajayega once mei
//         // if 8 is only needed once, if it's needed multiple times, abc and ab*c need to skip * so-
//     }
//     else{
//         return dp[m][n] = 0;   // straight up mis-match duh! =_=
//     }
    
// }

// int Solution::isMatch(const string s, const string p) {
//     int m = s.size();
//     int n = p.size();
//     vector<vector<int>> dp(2, vector<int> (n+1, -1));
//     // return match(s, p, m, n, dp);  
//     int bi;
    
//     dp[0][0] = 1;
    
//     for(int i=1; i<2; i++){
//         dp[i][0] = 0;
//     }
        
//     for(int j=1; j<=n; j++){
//         if(p[j-1] != '*'){
//             dp[0][j] = 0;
//         }
//         else{
//             dp[0][j] = dp[0][j-1];
//         }
//     }
        
//     for(int i=1; i<=m; i++){
//         bi = i&1;
//         for(int j=1; j<=n; j++){
//             if((s[i-1] == p[j-1]) || (p[j-1] == '?')){
//                 dp[bi][j] = dp[1-bi][j-1];
//             }
//             else if(p[j-1] == '*'){
//                 dp[bi][j] = dp[1-bi][j] || dp[bi][j-1];
//             }
//             else{
//                 dp[bi][j] = 0;
//             }
//         }
//     }
//     return dp[bi][n]; 
// }
    
// // cbcacacabac
// // c
