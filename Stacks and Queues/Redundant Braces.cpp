bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// since characters are insignificant(non-operator) hence we don't bother about them
// works 'cause A will be always a valid expression as given

int Solution::braces(string A){
    int n=A.size();
    stack<int> s;
    for(int i=0; i<n; i++){
        if(A[i]=='(' || isOperator(A[i])){
            s.push(A[i]);
        }
        else if(A[i]==')'){
            if(s.top()=='(') return true;   // hume bss atleast 1 galti dhoondni hai
            while(isOperator(s.top())){
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}
 