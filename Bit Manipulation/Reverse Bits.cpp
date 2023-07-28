unsigned int Solution::reverse(unsigned int A) {
    //Left to Right mirror image - 0th bit becomes 31st bit... nth bit becomes (31-n)th bit
    
    unsigned int ans=0;
    int i=0, n=32;
    
    while(n--){
        if(A&(1<<i++)){    //checking if ith bit is set or not, if yes then -->
            ans = (ans | 1<<(32-i));    //it will set the bit in reverse, CAREFUL about 32-i
        }   //i++ DO NOT DO THIS.  else... ;(       ??????? upar 32-i mei issue
    }
    return ans;
}


