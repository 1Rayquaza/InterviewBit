// power long long mei aa rhi hai, toh ll ko int mei convert krke issuesss so- har jageh long long krdo
long long power(long long a, long long b){    // returns (a^b)%m
    int m=1e9+7;
    if(b<1) return 1;
    // a^(b/2)*a^(b/2)
    long long p=power(a,b/2);
    p=((p%m)*(p%m))%m;
    if(b%2==0) return p;
    else return ((p%m)*(a%m))%m;
}

long long mInverse(int a){
    int m=1e9+7;
    //Inverse only possible when gcd(a,m)=1
    return power(a, m-2);
}

int Solution::solve(int A, vector<int> &B) {
    
    /* If a city with index i is visited, you can visit either the city with index i-1 (i >= 2) or 
    the city with index i+1 (i < A) if they are not already visited 
    
    2 types: 1 at either end, can only be traversed in one way and other in the middle with multiple permutations
    Although these two types can also have multiple permutations so, n! for n not visited cities divided by bla blah idk */
    // 1 2^(x-1) 2^(y-1) ... 1 (1 way for each start and end)
    
    int n=B.size();
    int m=1e9+7;
    sort(B.begin(), B.end());
    vector<long long> v;
    v.push_back(B[0]-1);
    for(int i=1; i<n; i++){
        v.push_back((B[i]-B[i-1]-1));
    }
    v.push_back((A-B[n-1]));    //A is total cities
    
    //segments size done
    //((A-n)! / segments size factorials ) * 2^(segment size - 1) ...jitne bhi segments h sbke liye
    //pre-compute all factorials with modulo m
    
    vector<long long> fact(A+1);  //hash mei size define krna chaiye
    fact[0]=1;
    for(int i=1; i<A+1; i++){
        fact[i]=((fact[i-1]%m)*(i%m))%m;
    }
    
    long long temp=1;
    for(int j=0; j<v.size(); j++){
        temp=((temp%m)*(fact[v[j]]%m))%m;   //Denominator
    }    
    
    int uv=fact[A-n];
    long long temp2=uv;
    for(int i=1; i<v.size()-1; i++){
        temp2= ((temp2%m) * ((power(2, v[i]-1))%m))%m;
    }
    // cout << temp << " " << temp2 << " " << mInverse(temp) << " " ;
    // (temp2/temp1)%m where m is prime
    // which is equal to (temp2*mInverse(temp1))%m
    
    long long ans = 1;
    ans = ((temp2%m)*(mInverse(temp)%m))%m;
    return ans;
}