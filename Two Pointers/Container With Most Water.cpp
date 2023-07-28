int Solution::maxArea(vector<int> &A) {
    /* index diff for base, min(num1, num2) for height since no slanting allowed maximise the product 
    of above two i.e. maxm. index diff. -> pointers on start and end then compare numbers
    Keep storing and updating. */
    int n=A.size();
    if(n==1) return 0;
    int i=0, j=n-1;
    int ans=INT_MIN;
    int base, h, area;
    
    while(i<j){
        base=(j-i);
        h=min(A[i], A[j]);
        area=(base*h);
        ans=max(ans, area);
        if(A[i]<A[j]){  //if(A[i+1]<A[j-1]){ <- AVOID 'cause pcurrent element ignore ho jaayega aaye
            i++;
        }
        else j--;
    }
    return ans;
}
