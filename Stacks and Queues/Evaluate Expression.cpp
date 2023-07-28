/* Reverse Polish notation (RPN) is a method for representing expressions in which the operator symbol is 
placed after the arguments being operated on 
13  5   / implies 13/5*/

int Solution::evalRPN(vector<string> &A) {
    int n=A.size();
    stack<int> s;
    int a, b;
    for(int i=0; i<n; i++){
        if(A[i] == "+" or A[i] == "-" or A[i] == "*" or A[i] == "/"){
            b=s.top();  // for denominator
            s.pop();
            a=s.top();
            s.pop();
            
            int temp;
            if(A[i]=="+") temp=a+b;
            else if(A[i]=="-") temp=a-b;
            else if(A[i]=="*") temp=a*b;
            else temp=(a/b);
            s.push(temp);
        }
        else s.push(stoi(A[i]));    // A[i] may be negative so don't define limit
    }
    return s.top();
}
