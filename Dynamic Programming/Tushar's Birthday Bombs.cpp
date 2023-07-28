vector<int> Solution::solve(int A, vector<int> &B) {
    int n=B.size();
    
    // map for looking up the lexicographical indices, baad mei sort kr denge
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        if(mp.find(B[i]) == mp.end()){
            mp[B[i]] = i;
        }
    }
    int idx = min_element(B.begin(), B.end()) - B.begin();
    int mn = *min_element(B.begin(), B.end());
    // cout << idx << " " << mn << " ";
    
    // max kicks can come with min element only, however, to maximise total strenghh AND kicks, 
    // we'll see if we can replace any of that min element by something of more strength but <=A
    int x = A/mn;
    vector<int> ans;
    for(int i=0; i<x; i++){
        ans.push_back(mn);
    }
    int sum = mn*x;
    
    int j=0;
    for(int i=0; i<idx; i++){  // try update answer if strenght is not reached, ct is already max 'cause min element was take
        while(j<ans.size() && (sum + (B[i]-mn) <= A)){
            ans[j] = B[i];
            sum += (B[i]-mn);
            j++;
        }
    }
    // TC: O(2*N): j bhi i ke saath ek hi baar chal rha hai
  
    for(int i=0; i<ans.size(); i++){
        ans[i] = mp[ans[i]];    
    }
    // sort(ans.begin(), ans.end()); already start se traverse kr rhe so lexicographical only
    return ans;
}
