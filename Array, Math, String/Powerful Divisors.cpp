vector<int> pow(int n){
    vector<int> v(n+1, 1); //v[0]=0; 1 extra for the number itself since 0-based indexing
    v[0]=0;
    for(int i=2; i<n+1; i++){   //Using sieve to calculate the occurance of each no. as a divisor :O *****
        for(int j=i; j<n+1; j+=i){   //Instead of calculating divisors individually, we can increment the multiples for each number.
            v[j]++;
        }
    }
    
    for(int i=1; i<n+1; i++){
        int t=v[i];
        if((t&(t-1)) == 0){
            v[i]=1;
        }
        else v[i]=0;
    }
    return v;
}

vector<int> Solution::powerfulDivisors(vector<int> &A) {
    //Pre-computaion if no. can be Y or not; prefix sum for each number
    // int n=A.size();
    // int mx=INT_MIN;
    // for(int i=0; i<n; i++){
    //     mx=max(mx, A[i]);
    // }
    int mx = *max_element(A.begin(), A.end());
    //we got the no. mx jahan tk calculate krna hai
    vector<int> temp=pow(mx);
    for(int i=1; i<temp.size(); i++){
        temp[i]+=temp[i-1];
    }
    
    vector<int> ans;
    for(auto value:A){
        ans.push_back(temp[value]);
    }
    return ans;
}
