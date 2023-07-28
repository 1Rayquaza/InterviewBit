int Solution::isPower(int A) {
    // if(A<=0){
    //     return false;
    // }
    // else if(A==1){
    //     return true;
    // }
    // else{
    //     for(int i=2; i*i<=A; i++){   //square power hogi atleast, so root will be <= square root only
    //     double temp = log(A)/log(i);    //'cause aise int form mei aayega and always true hoga
    //         if( pow(i,(int)temp) == A ){  //(ceil(temp) == floor(temp)) NOT WORKING WHY???  pow(a,x)=a^x
    //             return true;              //upar mei cpp mei poora accurate nhi aata so 1 ka 0 ho jaata h isliye kuch considerable difference will be accepted
    //         }
    //     }
    // }
    // return false;
    
    if(A==1) return 1;
    for(int i=2;i*i<=A;i++){
        if(A%i==0){
            for(int j=2;j<32;j++){
                if(pow(i,j)==A) return 1;
            }
        }
    }
    return 0;
}
