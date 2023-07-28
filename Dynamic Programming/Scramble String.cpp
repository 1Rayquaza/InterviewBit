unordered_map<string, bool> m;
// MCM nicey question
bool solve(const string &A, const string &B){
    if(A.compare(B) == 0){
        return true;
    }
    if(A.size() <= 1){
        return false;
    }
    
    string tmp = A + "_" + B;
    if(m.find(tmp) != m.end()){
        return m[tmp];
    }
    
    int n = A.size();
    for(int i=1; i<=n-1; i++){   // i is length
        bool b1 = solve(A.substr(0, i), B.substr(n-i, i)) && solve(A.substr(i, n-i), B.substr(0, n-i));
        bool b2 = solve(A.substr(0, i), B.substr(0, i)) && solve((A.substr(i, n-i)), B.substr(i, n-i));
        if(b1 || b2){
            return m[tmp] = true;
        }
    }
    return m[tmp] = false;
}

int Solution::isScramble(const string A, const string B) {
    m.clear();
    int n = A.size();
    int m = B.size();
    if(n != m){
        return 0;
    }
    return solve(A, B);
}
