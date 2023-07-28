int Solution::nchoc(int A, vector<int> &B) {
    int n=B.size();
    int m=1e9+7;
    // we need the bags with max. chocolates, however, the bag which is halved may still be max. so needs to
    // be accounted for - top K(max) should be accounted first - max heap
    priority_queue<int> maxH;
    for(int i=0; i<n; i++){
        maxH.push(B[i]);
    }
    
    int sum=0;
    for(int i=0; i<A; i++){ // got A units time
        int c = maxH.top();
        maxH.pop();
        sum = (sum%m + c%m)%m;
        maxH.push(c/2);
    }
    return sum;
}
