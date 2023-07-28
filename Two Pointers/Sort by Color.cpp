void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //sort(A.begin(), A.end()); - OK but-
    //Inbuilt sort functions not allowed :) so-
    
    int n=A.size();
    int i=0, s=0, e=n-1;
    while(i<=e){
        if(A[i]==0){
            swap(A[i], A[s]);
            s++;
        }
        else if(A[i]==2){
            swap(A[i], A[e]);
            e--;
            i--;    //Last se jo element utha kr laa rhe uska kya pta toh isliye dubaara check krna hai
        }
        i++;
    }
}
