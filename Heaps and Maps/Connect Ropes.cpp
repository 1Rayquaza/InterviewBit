int Solution::solve(vector<int> &A) {
    int n=A.size();
    // it'd be beneficial to connect ropes from shortest to longest
    // we need min elements first so max heap
    priority_queue<int, vector<int>, greater<int>> minH;
    for(int i=0; i<n; i++){
        minH.push(A[i]);
    }
    
    int sum=0;
    while(minH.size()>1){
        int x = minH.top();
        minH.pop();
        int y = minH.top();
        minH.pop();
        int c = x+y;
        sum += c;
        minH.push(c);
    }
    
    return sum;
}
