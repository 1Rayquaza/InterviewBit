unordered_map<int, vector<string>> dp;

vector<string> solve(string &A, int i, unordered_map<string, bool> &mp){
    if(i == A.size()){
        return {};
    }
    
    if(dp.find(i) != dp.end()){
        return dp[i];
    }
    
    vector<string> ans;
    string s;
    for(int k=i; k<A.size(); k++){
        s = A.substr(i, k-i+1);
        
        string tmp = "";
        if(mp.find(s) != mp.end()){
            tmp += s;
            tmp += " ";
            vector<string> res = solve(A, k+1, mp);
            
            if(res.size() > 0){
                for(int x=0; x<res.size(); x++){
                    string t = tmp; // baaki time only required space hoga, no extra
                    t += res[x];
                    ans.push_back(t);
                } 
            }
            else if(k+1 == A.size()){
                tmp.pop_back(); // last waale space ko hatane ke liye
                ans.push_back(tmp);
            }
            
        }
    }
    return dp[i] = ans;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    int n=A.size();
    int m=B.size();
    
    dp.clear();
    
    unordered_map<string, bool> mp;
    for(int i=0; i<m; i++){
        mp[B[i]] = 1;
    }
    
    return solve(A, 0, mp);
}


/*
aabbbabaaabbbabaabaab
9 bababbbb bbbabaa abbb a aabbaab b babaabbbb aa bb
*/

//a a b b b a b a a a b b b a b a a b a a b a a b b b a b a a a b b b a b a a b aa b a a b b b a b a a a b b b a b aa b a a b a a b b b a b a a a b b b a b aa b aa b a a b b b a b a a a b bb a b a a b a a b a a b b b a b a a a b bb a b a a b aa b a a b b b a b a a a b bb a b aa b a a b a a b b b a b a a a b bb a b aa b aa b a a b b b a b a a a bb b a b a a b a a b a a b b b a b a a a bb b a b a a b aa b a a b b b a b a a a bb b a b aa b a a b a a b b b a b a a a bb b a b aa b aa b a a b b b a b a a a bbbabaa b a a b a a b b b a b a a a bbbabaa b aa b a a b b b a b a a abbb a b a a b a a b a a b b b a b a a abbb a b a a b aa b a a b b b a b a a abbb a b aa b a a b a a b b b a b a a abbb a b aa b aa b a a b b b a b a aa b b b a b a a b a a b a a b b b a b a aa b b b a b a a b aa b a a b b b a b a aa b b b a b aa b a a b a a b b b a b a aa b b b a b aa b aa b a a b b b a b a aa b bb a b a a b a a b a a b b b a b a aa b bb a b a a b aa b a a b b b a b a aa b bb a b aa b a a b a a b b b a b a aa b bb a b aa b aa b a a b b b a b a aa bb b a b a a b a a b a a b b b a b a aa bb b a b a a b aa b a a b b b a b a aa bb b a b aa b a a b a a b b b a b a aa b
//a a b b b a b a a a b b b a b a a b a a b a a b b b a b a a a b b b a b a a b aa b a a b b b a b a a a b b b a b aa b a a b a a b b b a b a a a b b b a b aa b aa b a a b b b a b a a a b bb a b a a b a a b a a b b b a b a a a b bb a b a a b aa b a a b b b a b a a a b bb a b aa b a a b a a b b