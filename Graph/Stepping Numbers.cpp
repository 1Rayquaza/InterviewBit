void dfs(int i, int A, int B, vector<int> &ans){
    if(i > B) return;
    int curr = i%10;    // bss ek digit mei difference chaiye
    
    if(i>=A && i<=B){
        ans.push_back(i);
    }
    
    if(curr != 0){
        dfs(i*10 + (curr-1), A, B, ans);    // adjacent no. chaiye, i.e. digit ct inc. by 1
    }
    
    if(curr != 9){
        dfs(i*10 + (curr+1), A, B, ans);
    }
    
}

vector<int> Solution::stepnum(int A, int B) {
    // digits wise krna would be more practical
    vector<int> ans;
    if(A <=0 && B >= 0) ans.push_back(0);   // given in submission :)) not q.
    
    for(int i=1; i<=9; i++){
        dfs(i, A, B, ans);
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}


