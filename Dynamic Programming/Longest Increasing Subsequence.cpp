// https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn/
int Solution::lis(const vector<int> &A) {
    // memset(dp, -1, sizeof(dp));
    int n = A.size();
    if(n == 1) return 1;
    
    vector<int> prev(n, -1); // It will store the indices of previous elements in LIS
    vector<int> v, vIdx; // vIdx gives the ORIGINAL index of the elements in the path
    v.push_back(A[0]);
    vIdx.push_back(0);  // vIdx is index of- v mei jo element h uske corresponding original index in A
    
    for(int i=1; i<n; i++){
        if(A[i] > v[v.size()-1]){
            prev[i] = (vIdx[vIdx.size()-1]);
            v.push_back(A[i]);
            vIdx.push_back(i);
        }
        else{
            int it = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
            if(it>0)
                prev[i] = vIdx[it-1];
            v[it] = A[i]; // * mtlb by address so original vector mei value change ho jayegi
            vIdx[it] = i;
            
        }
    }
    
    vector<int> path;
    int idx = vIdx[vIdx.size()-1];
    while(idx != -1){
        path.push_back(A[idx]);
        idx = prev[idx];
    }
    // reverse(path.begin(), path.end());
    // for(int i=0; i<prev.size(); i++){
    //     cout << prev[i] << " ";
    // }
    return path.size();
}

/*
agar const vector nhi given hota toh hun O(1) space mei bhi kr skte the, as vectore mei directly change
e.g. 2 6 8 3 4 5 1
2 6 8, compare with last element and we can see that new sequence needs to be there so
2 3 8, we only need the size so proceed this way(Greedy approach)
2 3 4 5
1 3 4 5
longest length = 4
*/
