int Solution::singleNumber(const vector<int> &A) {
    //XOR operation(gives 0 for same, and 1 for different bits) : x^x=0, x^0=x
    int num=0;
    for(int i=0; i<A.size(); i++){
        num=num^A[i];
    }
    return num;
}
