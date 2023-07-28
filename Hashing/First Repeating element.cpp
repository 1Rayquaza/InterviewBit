// Pre-Computation for O(N)
// We'll make a hashing array with count of elements; whichever gets updated to 2, it's index 
// will be stored in variable mn = min(mn, i)
// val of A high so prefer map

int Solution::solve(vector<int> &A) {
    int n = A.size();
    // int mn = INT_MAX;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[A[i]]++;
    }
    for(int i=0; i<n; i++){
        if(mp[A[i]]>1){
            return A[i];
        }
    }
    return -1;
}
