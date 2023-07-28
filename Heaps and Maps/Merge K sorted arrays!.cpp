vector<int> Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    // K sorted integer arrays  - use this to reduce TC 
    priority_queue<int, vector<int>, compare> minH; // we need to sort acc. to 
    for(int i=0; i<n; i++){
        int j=0;
        while(j<m){
            minH.push(A[i][j]);
            j++;
        }
    }
    // O(kn*log(kn)) to O(kn*log(k)), space O(k) from O(kn)
    vector<int> ans;
    while(minH.size() != 0){
        ans.push_back(minH.top());
        minH.pop();
    }
    return ans;
}
