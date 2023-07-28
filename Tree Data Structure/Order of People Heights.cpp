vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pair<int, int>> list;
    for(int i=0; i<A.size(); i++){
        list.push_back({A[i], B[i]});
    }
    sort(list.begin(), list.end());
    reverse(list.begin(), list.end());

    // 6 5 4 3 2 1
    // 0 0 2 1 2 3
    
    vector<int> ans;
    for(int i=0; i<list.size(); i++){
        ans.insert(ans.begin() + list[i].second, list[i].first);
    }
    return ans;
}