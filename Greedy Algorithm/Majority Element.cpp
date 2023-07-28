int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int num = n/2;
    
    // Can use moore votinfg algo as well
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[A[i]]++;
        if(mp[A[i]] > num) return A[i];
    }
    
    return -1;
}
