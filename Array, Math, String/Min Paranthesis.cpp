int Solution::solve(string A) {
    int n=A.size();
    int c=0;
    // )( exists
    //stack ?
    stack<int> st;
    
    for(int i=0; i<A.size(); i++){
        if(A[i]=='('){ //opening-type
            st.push(A[i]);
        }
        else if(!st.empty() && A[i]==')'){
            st.pop(); 
        }
        else{
            c+=1;
        }
    }
        
    return c+st.size();
}

//Try it with map, let say (,{,[ teeno ka pucha ho, usko bhi solve kro