int Solution::solve(string A) {
    int n=A.size();
    stack<int> s; // assume '(' as +1 and ')' as -1
    for(int i=0; i<n; i++){
        if(A[i]=='('){
            s.push(1);
        }
        else if(s.size()!=0 && A[i]==')'){
            s.pop();
        }
        else return 0;
    }
    if(s.size()==0) return 1;
    else return 0;
}
