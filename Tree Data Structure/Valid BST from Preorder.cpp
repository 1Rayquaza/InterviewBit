int Solution::solve(vector<int> &A) {
    int n = A.size();
    set<int> s; // duplicates check
    for(int i=0; i<n; i++){
        s.insert(A[i]);
    }    
    if(s.size() != n) return 0;
    
    stack<int> st;
    int prev = INT_MIN;
    for(int i=0; i<n; i++){
                
        while(!st.empty() && A[i] > st.top()){
            prev = st.top();
            st.pop();
        }
        
        if(prev > A[i]) return 0;
        
        st.push(A[i]);
    }
    return 1;
}

/* Preorder - N L R
first ele is root, NGR is right child, NSR is left child

while the value keeps decreasing, it doesn't matter(left is smaller in BST)
when it inc. THEN, uske siblind and all descendents will be cleaned up

*/