#include <bits/stdc++.h>

vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    vector<int> tmp = A;
    sort(tmp.begin(), tmp.end(), greater<int>());

    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[A[i]] = i;
    }
    
    for(int i=0; i<n; i++){
        if(B == 0) break;
        
        int idx = mp[tmp[i]];
        if(A[i] != A[idx]){
            swap(A[i], A[idx]);
            mp[A[idx]] = idx;   // *** update
            B--;
        }
    }
    
    return A;
}