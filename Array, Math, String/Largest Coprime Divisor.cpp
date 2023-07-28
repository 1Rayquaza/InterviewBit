int Solution::cpFact(int A, int B) {
    // int di=B, de=A; //di = divisor, de = dividend
    
    // while(de%di != 0){
    //     int t = di;
    //     di = de%di, de = t;
    // }
    
    // if(di==1){
    //     return A;
    // }
    
    // // if(di|A && di|B){   //WTF, it's always true
    // // return 1;
    // // }
    // if(B>A){
    //     int c=B/di;
    //     if((A/di)%c==0){
    //         return 1;
    //     }
    //     else{
    //         return A/di;
    //     }
    // }
    
    // return A/di;
    
    int num = __gcd(A,B);
    if(num==1){
        return A;
    }
    return cpFact(A/num,B);
}
