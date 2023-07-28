vector<int> Solution::maxone(vector<int> &A, int B) {
    int s=0, e=0, n=A.size();
    int best_st = 0, len = 0;
    int c = 0;
    for (e=0; e<n; e++) {
        if (A[e] == 0) 
            c++;
        while (c>B){
            if (A[s] == 0) c--;
            s++;
        }
        int curr_len = e-s+1;
        if (curr_len > len) {
            len = curr_len;
            best_st = s;
        }
    }

    vector<int> v;
    for (int i = best_st; i < best_st + len; i++) {
        v.push_back(i);
    }
    return v;
}


// vector<int> Solution::maxone(vector<int> &A, int B) {
//     // maximum sequence of continuous 1's that can be formed by replacing AT-MOST B zeroes
//     // find 1 at righ end which is at max. distance from 1 at left end jinke beevh AT-MOST B zeroes ho AND vice-versa
//     // Pre-computation of suffix array of count of zeroes from the beginning and vice-versa
//     // O(NlogN)
//     // Kandane related ??
//     int n=A.size();
//     // 0 0 0 0 1 0 1
//     // 0 1 2 3 4 5 6
//     // 1 2 3 4 4 5 5
//     int c0=0;
//     vector<int> prefix(n);
//     for(int i=0; i<n; i++){
//         if(A[i]==0){
//             c0++;
//         }
//         prefix[i]=c0;
//     }
    
//     //prefix[j]-prefix[i] will give zeroes AFTER i till j index
//     int i=0;
//     int j=n-1;
//     int idx=0;
//     int s, e;
//     int total;
    
//     while(i<j){
//         if(i==0){
//             total = prefix[j];
//         }
//         else{
//             total = (prefix[j]-prefix[i-1]);
//         }
        
//         if(total>B){    //11 j--; 00 j--; 01 i++; 10j--
//             if((A[i]==0)&&(A[j]==1)){
//                 i++;
//             }
//             else{
//                 j--;
//             }
//         }
//         else{   //(prefix[j]-prefix[i])<=B) our answer
//             s=i;
//             e=j;
//             break;
//         }
//     }
    
//     int q = (j-i+1);
//     vector<int> ans(q);
//     for(int k=0; k<q; k++){
//         ans[k]=s;
//         s++;
//     }
//     return ans;
// }

