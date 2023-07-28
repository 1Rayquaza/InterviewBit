vector<vector<int> > Solution::anagrams(const vector<string> &A) {\
    int n=A.size();
    // Always think in simpler terms, strings were there to confuse, it's just finding occurances of a key
    // Let's sort each string, then comparison would be easier
    unordered_map<string, vector<int> > m;
    for(int i=0; i<n; i++){
        string tmp = A[i];
        sort(tmp.begin(), tmp.end());
        m[tmp].push_back(i+1);
    }
    
    // Assuming tmp as the key(since all anagrams of a word are equal now), now we just need to push the 
    // indices where the key is found i.e. push_back the corresponding vectors
    vector<vector<int> > v;
    for(auto it=m.begin(); it!=m.end(); it++){
        v.push_back(it->second);
    }
    return v;
}
