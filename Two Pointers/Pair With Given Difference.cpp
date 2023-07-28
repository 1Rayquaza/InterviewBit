int Solution::solve(vector<int> &A, int B) {
    //Unsorted Array
    int n=A.size();
    //to reduce O(NlogN) to O(N), replace maps with vectors
    vector<int> hashp((1e6+1), 0);
    vector<int> hashn((1e6+1), 0);
    for(int i=0; i<n; i++){
        if(A[i]>0){
            hashp[A[i]]++;
        }
        else{
            hashn[abs(A[i])]++;
        }
    }
    
    for(int i=0; i<n; i++){
        if(B==0){
            if((hashp[A[i]]>1) || (hashn[abs(A[i])]>1)) return 1;
            else continue;
        }
        if((A[i]-B)<0){
            if((hashn[abs(A[i]-B)]>0) || (hashn[abs(A[i]+B)]>0)){
                return 1;
            }
        }
        else if((A[i]-B)>0){
            if((hashp[A[i]-B]>0) || (hashp[A[i]+B]>0)){
            return 1;
            }
        }
    }
    
    return 0;
}
    
//     map<int, int> mp;
//     for(int i=0; i<n; i++){
//         mp[A[i]]++;
//     }
    
//     for(int i=0; i<n; i++){
//         if((mp[A[i]-B]) || (mp[A[i]+B])){
//             if(B==0){
//                 if(mp[A[i]]>1){
//                     return 1;
//                 }
//                 else continue;
//             }
//             return 1;
//         }
//     }
//     return 0;
// }
    
    // vector<int> hash1((1e3+1), false);
    // vector<int> hash2((1e3+1), false);
    
    // for(int i=0; i<n; i++){
    //     if(A[i]>=0){
    //         hash1[A[i]]=true;
    //     }
    //     else{
    //         hash2[abs(A[i])]=true;
    //     }
    // }
    
    
    // int m=1e3+1;
    // int l=0, r=1;
    // while(l<r && r<m){
    //     if(hash1[l]==true && hash1[r]==true){
    //         int d=abs(hash2[r]-hash2[l]);
    //         if(d==B) return 1;

    //         else if(d>B){
    //             l++;
    //             if(r==l){
    //             r++; 
    //             }
    //         } 
    //         else{
    //             r++;
    //         }
    //     }
    //     else{
    //         if(hash1[l])
    //     }
        
    // }
    
    
    // return 0;
