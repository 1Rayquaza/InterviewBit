// Approach 1
int Solution::seats(string A) {
    // TOTAL jumps should be minimum
    // *** people cannot cross anyone and sit, only move to adjacent seat !
    int mod = 1e7+3;
    int n = A.size();
    
    vector<int> p;
    for(int i=0; i<n; i++){
        if(A[i] == 'x'){
            p.push_back(i);
            // cout << p[i] << " ";
        }
    }
    
    int pn = p.size();
    if(pn <=1) return 0;
    int median = p[pn/2];
    // cout << "median = " median << " ";
    int mn = 0;
    int cost = 0;
    for(int k=pn/2-1; k>=0;){
        int d = (median - 1) - p[k];
        median--;
        k--;
        cost = (cost + d)%mod;
    }
    
    median = p[pn/2];
    for(int k=pn/2+1; k<pn;){
        int d = p[k] - (median + 1);
        median++;
        k++;
        cost = (cost + d)%mod;
    }
    
    return cost;
}
  
    
// 0 1 2 3 4 5
// x x . m . x
// ....x..xx...x..

// Approach 2
int Solution::seats(string A) {
    // TOTAL jumps should be minimum
    // *** people cannot cross anyone and sit, only move to adjacent seat !
    int mod = 1e7+3;
    int n = A.size();
    
    // 1 <= N <= 1e6
    int total = 0;
    for(int i=0; i<n; i++){
        if(A[i] == 'x') total++;
    }
    
    int left = 0, cost = 0;
    for(int i=0; i<n; i++){
        if(A[i] == 'x') left++;
        else{
            cost = (cost + min(left, total-left))%mod;  // har vacant position ke liye ek step kis direction se log move kren ye dekh rhe
        }
    }
    
    return cost;
}
