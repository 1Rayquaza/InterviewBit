bool isPossible(vector<int> &A, int B, int mid){
    int n=A.size();
    int pages=0;
    int student=1;
    for(int i=0; i<n; i++){
        pages+=A[i];
        if(pages > mid){
            student++;
            pages=A[i];
            // (commented after above edit) i--;    //'cause this wt didn't add
        }
    }
    return student<=B;
}
int Solution::books(vector<int> &A, int B) {
    // so that the maximum number of pages allocated to a student is minimum.
    // min. 1 student ko 1 max. page waali book toh allot hogi hi, max. 1 ko saari allot hojaaye
    // same ship-conveyer problem
    int n=A.size();
    if(n < B) return -1;    // students zyada, book km
    int mx=0, sum=0;
    for(int i=0; i<n; i++){
        mx = max(mx, A[i]);
        sum += A[i];
    }
    if(B == n) return mx;   //ek student ko ek, so max page to 1 student
    if(B == 1) return sum;  //ek student ko sbb pdhna hai
    
    int lo=mx, hi=sum;
    while(hi - lo > 1){
        int mid = (lo+hi)/2;
        // let say a fn tell us if it's possible to distribute books with 'mid' no. of max pages
        // FF..FFFTT..TTT first true find krna hai
       if(isPossible(A, B, mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    if(isPossible(A, B, lo)) return lo;
    else return hi;
}
