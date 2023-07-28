// int dp[151][151][2];   3D matrix be tuff to imagine sooo... let's work with map!
unordered_map<string, int> m;

int solve(string &s, int i, int j, bool isTrue){
    if(i > j){
        return false;
    }
    
    if(i == j){
        if(isTrue == true){
            return (s[i] == 'T');   // if eval is True, the single char should be true
        }
        else {
            return (s[i] == 'F');   // it's a conditional statement uff
        }
    }
    
    string tmp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
    if(m.find(tmp) != m.end()){
        return m[tmp];
    }
    
    int ans = 0;
    for(int k=i+1; k<=j-1; k+=2){
        int lT = solve(s, i, k-1, true);
        int lF = solve(s, i, k-1, false);
        int rT = solve(s, k+1, j, true);
        int rF = solve(s, k+1, j, false);
        
        if(s[k] == '|'){
            if(isTrue == true){
                ans = ans + (lT*rF) + (lT*rT) + (lF*rT);
            }
            else{
                ans = ans + (lF*rF);
            }
        }
        else if(s[k] == '&'){
            if(isTrue == true){
                ans = ans + (lT*rT);
            }
            else{
                ans = ans + (lT*rF) + (rT*lF) + (lF*rF);
            }
        }
        else if(s[k] == '^'){
            if(isTrue == true){
                ans = ans  + (lT*rF) + (rT*lF);
            }
            else{
                ans = ans + (lT*rT) + (rF*lF);
            }
        }
    }
    
    return m[tmp] = ans%1003;
}

int Solution::cnttrue(string s) {
    m.clear();
    int n = s.size();
    return solve(s, 0, n-1, true)%1003;
}

// Hidden parameter !!! to make expression true, we may need True OR False ! so we'll also pass a parameter
// to tell which boolean expression needs to be calculated
