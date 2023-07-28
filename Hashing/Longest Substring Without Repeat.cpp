int Solution::lengthOfLongestSubstring(string A) {
    int n=A.size();
    if(n==1) return 1;
    // first think, then code
    // String consists of lowerCase,upperCase characters AND DIGITS
    vector<int> m(256,0);   // har character ki ASCII key ke corresponding store kraana
    int i=0, s=0, c=0;
    int mx = 1;
    
    while(i<n){ // ek baar traverse
        if(m[A[i]]==0){ 
            m[A[i]] = 1;
            c++;
        }
        else{
            while(A[s] != A[i]){    // ek baar traverse
                m[A[s]] = 0;        // so overall TC: O(2*N) = O(N) yayy or O(N*logN) because map 
                s++;
                c--;
            }
            s++;
            m[A[i]] = 1;
        }
        mx = max(mx, c);
        i++;
    }
    return mx;
}
