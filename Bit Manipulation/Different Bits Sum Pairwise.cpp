int Solution::cntBits(vector<int> &A) {
    int n=A.size();
    long long c0=0, c1=0;   //long long rkhna tha,
    int m=1000000007;
    int ans=0;
    //permutation of a and b is ab(repeatation allowed)
    
    for(int i=0; i<32; i++){
        for(int j=0; j<n; j++){
           if((A[j]&(1<<i))==0){
               c0++;    //saarei hi pair krne so alg-alg kro ya ek saath, does NOT make any difference
           } 
           else{
               c1++;
           }
        }
        long long temp = ((c0%m)*(c1%m))%m ;
        long long t = (2*temp)%m ;
        ans = ((ans%m) + (t%m))%m ; //no. of one's jo answer mei add honge
        c0=0;
        c1=0;
    }
    
    return ans;
    
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         num=(A[i]^A[j]);
    //         c= ((c%m)+(2*(__builtin_popcount(num))%m))%m;
    //     }
    //     num=0;
    // }
    //return c;
    //TIME LIMIT EXCEEDED
    
}
