// int Solution::numSetBits(unsigned int A) {
//     int c=0;
    
//     //*********
//     while(A!=0){
//         A=A&(A-1);  //(A-1) finds the first bit from the end, and set it to 0, and set all the bits(1's) following it
//         c++;        //so, one '1' bit would be turned to zero with every '&'
//     }
//     return c;
//     //return __builtin_popcount(A);
// }

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];    //i+1;
    }
    
    int ans=0;
    int temp=0;
    for(int i=n-1; i>=0; i=i-k){
        ans+=A[i];
    }
    
    cout << ans << endl;
    return 0;
}

// 1 2 3 4 5 6 7 8     3
// 1 2,3 4 5,6 7 8
// 0 1 2 3 4 5 6 7
