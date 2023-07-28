int dp[101][101][1001];
bool solve(vector<int> &A, int sum, int n, int l, vector<int> &tmp, vector<int> &subA){
    if(l == 0){ // or l>n 'cause we need to ensure that only l elements are used
        if(sum == 0){
            subA = tmp;
            return 1;
        }
        else return 0;
    }
    
    if(n == 0){
        return 0;
    }
    
    if(dp[n][l][sum]!=-1)
        return dp[n][l][sum];
    
    if(A[n-1] <= sum){
        tmp.push_back(A[n-1]);
        if(solve(A, sum-A[n-1], n-1, l-1, tmp, subA))
            return dp[n][l][sum] = true;
            // we returned here only since lexicographically smallest so jo elements aaye lete jao
        tmp.pop_back();
        return dp[n][l][sum] = solve(A, sum, n-1, l, tmp, subA);
    }
    else{
        return dp[n][l][sum] = solve(A, sum, n-1, l, tmp, subA);
    }
}

// We need to see if there's a subset with average as same as avg.

vector<vector<int> > Solution::avgset(vector<int> &A) {
    int n = A.size();
    memset(dp,-1,sizeof(dp));
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += A[i];
    }
    //vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (n+1, vector<int> (sum+1)));
    vector<vector<int>> ANS;
    int avg = sum/n;    // int ?
    // if(sum%n != 0) return ANS;
    
    sort(A.begin(), A.end(), greater<int>());   // for lexicographical order, reverse se traversal so-
    vector<int> subA;
    for(int l=1; l<=n-1; l++){  // l is length of subarray A
        vector<int> tmp;
        int subsetsum = (l*sum)/n;
        
        if((l*sum)%n != 0){
            continue;
        }
        
        if(solve(A, subsetsum, n, l, tmp, subA)){
            break;
        }
    }
    
    // subA contains first subarray
    vector<int> subB;
    
    if(subA.size() == 0){
        return ANS;
    }
    
    int i = subA.size()-1;
    int j = n-1;
    sort(A.begin(), A.end());
    while(i>=0 && j>=0){
        if(subA[i] == A[j]){
            i--;
        }
        else{
            subB.push_back(A[j]);
        }
        j--;
    }
    while(j>=0){
        subB.push_back(A[j]);
        j--;
    }
    reverse(subB.begin(), subB.end());
    ANS.push_back(subA);
    ANS.push_back(subB);
    return ANS;
}

// Q. is, Can I select current_size values from the array whose sum is current_sum ?
