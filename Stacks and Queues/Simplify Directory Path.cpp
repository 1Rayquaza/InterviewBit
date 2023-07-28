// In Unix-style file system:
// '.' refers to the current directory -> CONTINUE
// '..' refers to previous directory  -> pop() from stack
// Any multiple consecutive slashes '//' are treated as a single slash '/' -> can be added in the end

string Solution::simplifyPath(string A) {
    int n=A.size();
    stack<string> s;
    int i=0;
    while(i<n){
        string temp="";
        if(A[i]=='/'){
            i++;
            continue;
        }
        else if(A[i]=='.' && i+1< n && A[i+1]=='/'){ // added i+1<n because if i is last index then i+1 is out of bound so can throw runtime error
            i+=2;
            continue;
        }
        else if(A[i]=='.' && i+1< n && A[i+1]=='.' && s.size()==0){
            i+=2;
            continue;
        }
        else if(A[i]=='.' && i+1< n && A[i+1]=='.' && s.size()!=0){
            s.pop();
            i+=2;
        }
        else if(A[i]=='.'){ // case when string ends with . then i+1 does not exists so was going in while loop so add this cond here
            i++;
        }
        else{
            while(i<n && A[i]!='/' && A[i]!='.'){
                temp.push_back(A[i]);
                i++;
            }
            if(temp!=""){
                s.push(temp);
            }
        }
    }
    
    if(s.size()==0) return "/";
    
    string path="";
    while(s.size()!=0){
        string t=s.top();
        reverse(t.begin(), t.end());
        t.push_back('/');
        path.append(t); // appending the string at end
        s.pop();
    }
    reverse(path.begin(), path.end());
    return path;
}