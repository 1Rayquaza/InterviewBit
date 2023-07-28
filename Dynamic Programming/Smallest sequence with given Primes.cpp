vector<int> Solution::solve(int A, int B, int C, int D) {
    priority_queue<int, vector<int>, greater<int>> minH;

    minH.push(A);
    minH.push(B);
    minH.push(C);
    
    set<int> s;
    unordered_map<int, int> m;
    m[A]++;
    m[B]++;
    m[C]++;
    
    while(s.size() < D){
        int n = minH.top();
        minH.pop();
        s.insert(n);
        
        // push only if not already available
        if(m.find((n*A)) == m.end()){
            minH.push(n*A);
            m[(n*A)]++;
        }
        if(m.find((n*B)) == m.end()){
            minH.push(n*B);
            m[(n*A)]++;
        }
        if(m.find((n*C)) == m.end()){
            minH.push(n*C);
            m[(n*A)]++;
        }
    }
    
    vector<int> ans(s.begin(), s.end());
    return ans;
}

// 3 ptr for 3 factors, to see their current state and select the min. out of the three
// A, B, C - factors.
