int Solution::singleNumber(const vector<int> &A) {
    // 3X VS 3X+1 COUNT of BITS
    //for every 'i'th position, count no. of 1's and 0's, if count is 3x then nth, else 3x+1 implies ith bit value for 'x'
    int c0=0;
    int c1=0;
    int n=A.size();
    int ans=0;
    
    for(int i=0; i<31; i++){    //+ve only -> signed -> 31 bits 
        for(int j=0; j<n; j++){    //32N is linear only
            if((A[j]&(1<<i))==0){   //sbka 0th bit fir 1st bit then 2nd bit... ith bit check krte jaa rhe 
                c0++;               //****** (A[j]&(1<<i)==0) BRACKETS IMPORTANT T_T 'cause '==' ki priority zyada h so 
  
            }
            else{
                c1++;
            }
        }
        if(c1%3!=0){
            //'i'th bit is 1 i.e. we need to set ith bit
            ans=ans|(1<<i);
        }
        // else{
        //     //ith bit is 0, default
        // }
        c0=0;
        c1=0;
    }
    return ans;
}
