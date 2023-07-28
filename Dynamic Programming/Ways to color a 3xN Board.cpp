int m = 1e9+7;
long long modsum(long long a, long long b){
    long long ans = ((a%m) + (b%m))%m;
    return ans;
}

int Solution::solve(int A) {
    vector<long long> C2(A, 0);
    vector<long long> C3(A, 0);
    
    C2[0] = 12*1ll;
    C3[0] = 24*1ll;
    
    for(int j=1; j<A; j++){
        C2[j] = modsum(5*C3[j-1], 7*C2[j-1]);
        C3[j] = modsum(11*C3[j-1], 10*C2[j-1]);
    }
    
    return modsum(C2[A-1], C3[A-1]);
}
