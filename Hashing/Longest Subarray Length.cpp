int Solution::solve(vector<int> &A) {
    int n=A.size();
    for(int i=0; i<n; i++){
        if(A[i]==0) A[i]=-1;
    }    
    // find the longest subarray having sum 1
    // same approach as Largest Continuous Sequence Zero Sum
    unordered_map<int, int> m;
    int sum=0, len=0, ans=0;
    for(int i=0; i<n; i++){
        sum += A[i];
        if(m.find(sum) == m.end()){
            m[sum] = i;
        }
        if(sum == 1){   // direct subarray from 0 to i index
            ans = max(ans, i+1);    // i+1 is length
        }
        else{   // a subarray with c1 one less than current subarray, if removed we'll get the reqd.
            if(m.find(sum-1) != m.end()){
                len = i-m[sum-1];
                if(len > ans){
                    ans = len;
                }
            }
            // we're removing the subarray so (i-sum) is not valid
            else continue;
        }        
    }
    return ans;
}

/*  Whenever encountered with q with 2 no., make them complement of each other so sum 0 implies equal 
    occurance, and we are left with one parameter to check(sum) instead of two(c0 & c1)
    We need to find the length of the longest subarray having count of 1’s one more than count of 0’s.
    READ QUESTIONS PROPERLY T_T - c1 is one more than c0
*/