vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
    // Return the maximum C valid sum combinations from all the possible sum combinations.
    // sum = A[i] + B[j] for any i and j
    // However, we need to do this in max O(NlogN) time so can't run 2 loops to see all and select C
    // sort both in descending order then move
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    set<pair<int, int>> s;   // to validate unique combination
    priority_queue<pair<int, pair<int, int>>> maxH;
    // to avoid repetation, we'll store sum AND indices, get max from heap top -> pop -> new max. obtained 
    maxH.push({A[0]+B[0], {0, 0}});
    s.insert({0, 0});
    // now we need to store sum in heap, and keep updating
    
    vector<int> ans;
    while(n--){
        pair<int, pair<int, int>> p = maxH.top();
        maxH.pop();
        int val = p.first;    // first is the sum
        ans.push_back(val);
        
        int i = p.second.first;
        int j = p.second.second;
        // cout << val << " " << i << " " << j << endl;
        // taking sum of next element of A keeping element of B
        int s1 = A[i+1] + B[j];
        if(s.find({i+1, j}) == s.end()){
            maxH.push({s1, {i+1,j}});
            s.insert({i+1, j});
        }
        
        int s2 = A[i] + B[j+1];
        if(s.find({i, j+1}) == s.end()){
            maxH.push({s2, {i,j+1}});
            s.insert({i, j+1});
        }
    }    
    return ans;
}


  