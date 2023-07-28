int Solution::solve(vector<int> &A, int B) {
    // similar to largest continuous sequence zero sum
    int n=A.size();
    int c=0;
    vector<int> v(n);
    v[0] = A[0];
    for(int i=1; i<n; i++){
        v[i] = v[i-1]^A[i]; // prefix XOR array done
    }
    
    // we know that A^B = C implies B^C = A
    // if XOR of one subarray is x, then we need to find if there's a y s.t. x^B=y 'cause that mean x^y=B
    // but how to account for repeatation ??? sorted below hehe
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        if(v[i] == B) c++;   // single element is also a subarray
        int temp = v[i]^B;
        c += m[temp];   // dubaara temp aaya toh uss waale v[i] ke liye 2 honge, no repeatation
        m[v[i]]++;
    }
    return c;
}
    

// int Solution::solve(vector<int> &A, int B) {
//     int n=A.size();
//     int c=0;
//     for(int i=0; i<n; i++){
//         int temp = A[i];
//         if(temp == B) c++;
//         for(int j=i+1; j<n; j++){
//             temp = temp^A[j];
//             if(temp == B) c++;
//         }
//     }
//     return c;
// }

// // total subarrays are n*(n+1)/2