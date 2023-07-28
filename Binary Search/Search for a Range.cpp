int search(const vector<int> &A, int B, bool first) {
    int low = 0, high = A.size()-1, ans = -1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(A[mid]==B) { ans = mid; if(first) high=mid-1; else low = mid+1; }
        else if(A[mid] < B) low = mid+1;
        else high = mid-1;
    }
    return ans;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> result(2);
    result[0] = search(A, B, true);
    result[1] = search(A, B, false);
    return result;
}


        
// O(N) with vectors - first thought
//     int n=A.size();
//     vector<int> ans(2);
//     int i;
//     for(int j=0; j<n; j++){
//         if(A[j]==B){
//             i=j;
//             break;
//         }
//     }
    
//     for(int j=0; j<n; j++){
//         if(j>i && A[j]!=B){
//             ans[0]=i;
//             ans[1]=j-1;
//             return ans;
//         }
//         if(j==n-1 && A[j]==B){
//             ans[0]=i;
//             ans[1]=j;
//             return ans;
//         }
//     }
//     ans[0]=-1;
//     ans[1]=-1;
//     return ans;
// }
