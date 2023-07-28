// Find if there exists 2 indices i and j such that A[i] - A[j] = B and i != j.
int Solution::diffPossible(const vector<int> &A, int B) {
    int n=A.size();
    if(n==1) return 0;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[A[i]]++;
    }
    
    for(int i=0; i<n; i++){
        if(m.find(A[i]+B) != m.end() || m.find(A[i]-B) != m.end()){   // the no. is available
            return 1;
        }
    }
    return 0;
}
