void solve(vector<int> &v, int B, vector<int> &tmp, set<vector<int>> &ans, int i, int count){
    if(count > B) return;
    if(count == B){
        ans.insert(tmp);
        return;
    }
    if(i==v.size()) return;
    
    // if we skip the current element
    solve(v, B, tmp, ans, i+1, count);
    
    // if we consider the current element
    count++;
    tmp.push_back(v[i]);
    solve(v, B, tmp, ans, i+1, count);
    count--;
    tmp.pop_back();
}

// we're given an array consisting of no.s. 1 to n from which we need to select B no.s. and return 'em
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> v;
    for(int i=0; i<A; i++){
        v.push_back(i+1);
    }
    set<vector<int>> ans;
    vector<int> tmp;
    solve(v, B, tmp, ans, 0, 0);
    vector<vector<int>> finalAns(ans.begin(), ans.end());
    return finalAns;
}
