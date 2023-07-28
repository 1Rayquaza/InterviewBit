bool cmp(vector<int> v1, vector<int> v2){
    return v1[0] < v2[0];   
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    sort(A.begin(), A.end(), cmp);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(A[0][1]);
    
    int ct = 1;
    for(int i=1; i<n; i++){
        int start = A[i][0];
        int end = A[i][1];
        
        if(start >= pq.top()){
            pq.pop();
        }
        
        pq.push(A[i][1]);  
    }
    
    // only the meetings which cannot take place in same room will remain, 'cause unko koi pop krne nhi aaya
    return pq.size();
}


// if we need to find max meetings, 1 room
// sort - return (v1[1] < v2[1]);
// int ct = 1;
// int ansEnd = A[0][1];

// for(int i=1; i<n; i++){
//     if(A[i][0] >= ansEnd){
//         ct++;
//         ansEnd = A[i][1];
//     }
// }
// return ct;