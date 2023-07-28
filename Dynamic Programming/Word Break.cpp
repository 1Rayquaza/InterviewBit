
bool solve(int i, string s, vector<int> &dp, unordered_map<string, bool> &m) {
    if(i == s.size()) return true;
    if(dp[i] != -1) return dp[i];

    string tmp = "";
    for(int k=i; k<s.size(); k++){
        tmp.push_back(s[k]);
        if(m.find(tmp) != m.end()){
            if(solve(k+1, s, dp, m)){
                return dp[i] = true;
            }
        }
    }

    return dp[i] = false;
}

// the thing is, in PP I needed to check if partitioning a way will MINIMISE th ct but here, I just need to 
// see if I can or cannot, EASY! like if i just need to tell !! so return whenever it fits true !

int Solution::wordBreak(string s, vector<string> &words) {
    int n = s.size();
    vector<int> dp(n, -1);
    
    unordered_map<string, bool> m;
    for(int i=0; i<words.size(); i++){
        m[words[i]] = 1;
    }
    
    return solve(0, s, dp, m);
}