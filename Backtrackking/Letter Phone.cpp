void solve(string A, vector<string> v, vector<string> &ans, string &tmp, int i){
    if(i == A.size()){
        ans.push_back(tmp);
        return;
    }
    
    string s = v[A[i]-'0']; // it's A[i], and not i, so string ke numbers hi cover honge dw
    for(int j=0; j<s.size(); j++){ // covering all char corresponding to an integer
        tmp += s[j];
        solve(A, v, ans, tmp, i+1);
        tmp.pop_back();
    }
    
}

vector<string> Solution::letterCombinations(string A) {
    // size of strings would be same as size of A
    // similar to special strings question 
    // here, we've a special string which- 1. has size A.size()     2. ith element from ith element of v
    // first we require a proper structure to convey the data tho, sooo-
    
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    v.push_back("abc");
    v.push_back("def");
    v.push_back("ghi");
    v.push_back("jkl");
    v.push_back("mno");
    v.push_back("pqrs");
    v.push_back("tuv");
    v.push_back("wxyz");
    
    vector<string> ans;
    string tmp;
    solve(A, v, ans, tmp, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
