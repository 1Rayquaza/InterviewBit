int Solution::colorful(int A) {
    vector<int> digits;
    while(A>0){
        digits.push_back(A%10);
        A = A/10;
    }
    // at max. 10 digits so O(N2) is alright
    int n=digits.size();
    reverse(digits.begin(), digits.end());  // IMP. !! else subsequences will change, so will the products
    
    vector<int> prod;
    for(int i=0; i<n; i++){
        prod.push_back(digits[i]);
        int p = digits[i];
        for(int j=i+1; j<n; j++){
            p = p*digits[j];
            prod.push_back(p);
        }
    }
    
    // for(int i=0; i<prod.size(); i++){
    //     cout << prod[i] << " ";
    // }
    // cout << endl;
    
    sort(prod.begin(), prod.end());
    for(int i=0; i<prod.size(); i++){
        if(prod[i]-prod[i-1] == 0){
            return 0;
        }
    }
    return 1;
}
