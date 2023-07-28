int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    // XOR of either 2 of 3 numbers will give the third number
    // increase count and make both no.s 1 so they don't interrupt further
    unordered_map<int, int> mp;
    int c=0;
    
    for(int i=0; i<n; i++){
        if(mp[A[i]^B]){
            c++;
            mp[A[i]^B] = 1;
        }
        mp[A[i]]=1; // marking the presence of the element
    } 
    return c;
}
