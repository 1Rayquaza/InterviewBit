int Solution::solve(int A) {
    // for(int i=0; i<32; i++){
    //     if(A&(1<<i)){   //set h ya unset usse determine kr rhe
    //         return i;
    //     }
    // }
    int c=0;
    while(A!=0){
        int x=A&1;  //*** iterating from end, ek ek bit krte hue ***, A&1 will give 0 if last bit is zero
        if(x==0){   //1&0 will give 0, iska mtlb 0 h end digit
            c++;
        }
        else{
            break;
        }
        //x==0?c++:break;
        A=A>>1; //shifting so end digit is gone
    }
    return c;
}
