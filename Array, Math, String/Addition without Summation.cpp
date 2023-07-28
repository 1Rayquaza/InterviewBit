int Solution::addNumbers(int A, int B) {
    int c=0;    //carry
    /* doing XOR, 0+0, 0+1, 1+0 will be alright but what about 1+1?? 
    (i.e. =10, ie. 0 AND ek one to the left i.e. left shift !!! :O) 
    sooooo... ek carry waale 1 ko left mei UPDATE krte rhna*/
    while(A!=0){
        c=A&B; //will give the carry 1 jisko left shift krke add krdenge by doing XOR
        B=A^B; 
        A=c<<1; // A is not A anymore but rather carry add krne ka indicator
    }
    return B;   
}
    /* int c=0;
    int sum=0;
    
    for(int i=0; i<31; i++){
        c=0;
        if((A&(1<<i))!=0){  //brackets IMPORTANT !!!
            c++;
        }
        if((B&(1<<i))!=0){
            c++;
        }
        sum=sum+(c*(1<<i)); //????? NO arithmetic operators allowed sooo...
    }
    return sum; */
