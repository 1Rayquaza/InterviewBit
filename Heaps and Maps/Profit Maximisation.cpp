int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    // we need the max number of vacant seats possible, however, after being occupied, vacant seats count 
    // change and we may need to update the max so heap(max)
    priority_queue<int> maxH;
    for(int i=0; i<n; i++){
        maxH.push(A[i]);
    }
    
    int cost=0;
    for(int i=0; i<B; i++){
        int x=maxH.top();
        maxH.pop();
        cost += x;
        x = x-1;
        maxH.push(x);
    }
    return cost;
}
