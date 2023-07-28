int Solution::longestValidParentheses(string A) {
    // O(N)
    int n = A.size();
    stack<int> s;
    s.push(-1);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(A[i] == '(')
            s.push(i);
        else{
            if(s.size() == 1)   // -1 only, new beginning
                s.top() = i;
            else{
                s.pop();
                ans = max(ans , i-s.top());
            }
        }
    }
    return ans;
}