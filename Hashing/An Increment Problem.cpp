vector<int> Solution::solve(vector<int> &A) {
    int n=A.size();
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
    for(int i=0; i<n; i++){
        m[A[i]].push(i);
        if(m[A[i]].top() == i) continue; // first occurance so no change
        else{
            int idx = m[A[i]].top();
            A[idx]++;   // previous value incremented
            //m[A[i]] = i; // *** previous no. changed, this MAY be the first occurance now: 1 2 1 2 2
            // we need a queue to keep track of the  index of elements
            m[A[i]].pop();
            m[A[idx]].push(idx); // idx ko bhi A[idx] ke queue mei push krna h CONDITIONALLY
            // need to check if index of changed value is first occurance
        }
    }
    return A;
}
// 1 2 1 2 2
// 1:0, 2:1

// 1 2 1 2 2
// if mp[A[i]]==i continue;
// else int fo = mp[A[i]]; = 0
// v[fo] ++;
// 2 2 1 2 2
// 3 3 1 2 2

