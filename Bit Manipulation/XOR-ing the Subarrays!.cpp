int Solution::solve(vector<int> &A) {
    
    //pre-computation ..? No need
    //XOR is ASSOCIATIVE !!!
    //count of subarrays = n*(n+1)/2
    
    //OBSERVE   !!!
    //count the no. of times a no. occurs and the results are interesting
    //As the XOR of no. with itself is 0, we'll be left with very few no.s to be dealt with
    
    int n=A.size();
    int x=0;
    
    //for even sized array, a no. occurs even times in total
    if(n%2==0){ //e.g. [1,2]->2-2 | [1,2,3,4]->4-6-6-4
        return 0;
    }
    else{
        //even indexed no.s occur odd no. of times, e.g. [1,2,3]->3-4-3 | [1,2,3,4,5]->5-8-9-8-5
        //(so, for even times, it gets cancelled by itself and only 1 of that matters)
        for(int i=0; i<n; i+=2){
            x=x^A[i];
        }
    }
    return x;
}
