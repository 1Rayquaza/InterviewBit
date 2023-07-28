int Solution::solve(vector<int> &A, int B) {
    // O(N) or O(NlogN) allowed
    // sub-array !! continuous only, sliding window, let previous one go as abhi nhi toh baad mei bhi count bdhayega
    // Sliding window
    // Hint: c(B) - c(B-1) will give us the count of subarrays with B different elements
    // c(B) = count of subarrays with B or less than B distinct elements
    
    int n=A.size();
    int c1=0, c2=0, j=0;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[A[i]]++;
        while((m.size()>B)){
            m[A[j]]--;
            if(m[A[j]]==0){
                m.erase(A[j]);  //*********** 'cause value 0 but key will still be counted in size
            }
            j++;
        }
        c1=c1+(i-j+1);
    }
    
    m.clear();
    j=0;
    for(int i=0; i<n; i++){
        m[A[i]]++;
        while((m.size()>B-1)){
            m[A[j]]--;
            if(m[A[j]]==0){
                m.erase(A[j]);
            }
            j++;
        }
        c2=c2+(i-j+1);
    }
        
    return (c1-c2);