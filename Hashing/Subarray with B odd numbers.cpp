int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int> prefix(n);
    int c=0;
    // prefix array to store info about odd no. count
    for(int i=0; i<n; i++){
        if(A[i]%2 != 0){
            c++;
        }
        prefix[i] = c;
    }
    
    unordered_map<int, int> m;
    int ct=0;
    for(int i=0; i<n; i++){
        if(prefix[i] == B) ct++;    // subarray from 0 to i has odd count B
        int temp = prefix[i] - B;
        if(temp >= 0) ct += m[temp];
        // subtract subarrays with the extra count, jitne aise subarrays, utna ct inc.
        m[prefix[i]]++; // to check for occurance(for subtraction incase- )
    }
    return ct;
}

/*  we need to find i and j s.t. j-i==B
    4 3 2 3 4
    0 1 1 2 2 (odd count prefix array), arr[i] - arr[j] will give odd no. count from j+1 to i */

