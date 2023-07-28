// DEQueue would be perfect DSA for this problem as it supports insertion and deletion from both front and back
// Now, there would be times when next element is greater than max so only one comparison reqd.
// variable sized DEQueue
   
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n=A.size();
    int mx = INT_MIN;
    deque<int> dq;
    vector<int> ans;
    int l=0;    //window ke first element ke liye
    
    for(int i=0; i<n; i++){
        while(!dq.empty() && A[i]>dq.back()){
            dq.pop_back();
        }
        dq.push_back(A[i]);
        
        if(i>=B-1){ // 1 window over, now comparisons begin
            ans.push_back(dq.front());  // first window ka max and onwards
            
            // agr max element pichle window ke first element ke barabar h toh usko hata diya
            if(dq.front()==A[l]){ 
                dq.pop_front();
            }
            l++;
        }
    }
    return ans;
}

// O(N*B)
// vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
//     vector<int> C;
//     for(int i = 0; i <= A.size() - B; i++){
//         int mx = INT_MIN;
//         for(int j = 0; j < B; j++){
//             if(mx < A[i + j]){
//                 mx = A[i + j];
//             }
//         }
//         C.push_back(mx);
//     }
//     return C;
// }
    
// vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
//     int n=A.size();
//     int mx = INT_MIN;
    
//     vector<int> ans(1);
//     if(B>=n){
//         for(int i=0; i<n; i++){
//             mx = max(mx, A[i]);
//         }
//         ans[0]=mx;
//         return ans;
//     }
//     vector<int> C(n-B+1); 
    
//     mx = max(A[0], A[1]);
//     mx = max(mx, A[2]);  
//     int j=0;
//     C[j] = mx;
//     for(int i=1; i<n; i++){
//         j++;
//         if(A[i]>mx) C[j]=A[i];
//         else{
//             // need to find max of this window which will take O(N) hence overall O(N2) !!!
//             C[j]=mx; 
//         }
//     }
//     return C;
// }