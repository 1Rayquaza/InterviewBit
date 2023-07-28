 /* Return string array containaing all possible special strings in Lexicographic order
    Special string -
    1. length = n
    2. ith char of string = any character of ith string
    Duplicate strings are also considered
    1 <= N <= 5
    1 <= |Ai| <= 8
    
    Assume half string is generated, now we need to select ith element of string, from ith element of array
    
*/

void solve(vector<string> &A, int i, vector<string> &ans, string &tmp){ // tmp ko update krna hai
    if(i == A.size()){
        ans.push_back(tmp);
        return;
    }
    for(int j=0; j<A[i].size(); j++){
        tmp.push_back(A[i][j]);
        solve(A, i+1, ans, tmp);
        tmp.pop_back();
    }
}
    
vector<string> Solution::specialStrings(vector<string> &A) {
    int n=A.size();
    vector<string> ans;
    int index = 0;
    string tmp = "";
    // ["ab", "cd"]
    // "ac", "ad", recurse back, "bc", "bd"
    solve(A, index, ans, tmp);
    sort(ans.begin(), ans.end());
    return ans;
}
