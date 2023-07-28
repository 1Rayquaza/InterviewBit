int Solution::solve(vector<vector<int> > &A, int B) {
    //Pre-computation https://youtu.be/nZe7P674xZo
    //Pre-computation quesn. mei try to take 1 based indexing
    int n=A.size();
    vector<vector<int>> R(n,vector<int>(n));
    vector<vector<int>> C(n,vector<int>(n));
    
    //cummulative row sum
    for(int i=0; i<n; i++){
        int sumr=0;
        for(int j=0; j<n; j++){
            sumr+=A[i][j];
            R[i][j]=sumr;
        }
    }
    
    //cummulative column sum
    for(int i=0; i<n; i++){
        int sumc=0;
        for(int j=0; j<n; j++){
            sumc+=A[j][i];
            C[j][i]=sumc;
        }
    }
    
    //start waala matrix sum, iske baad iss "window" ko shift krte chalenge, by adding new sum and subtracting old one @N1
    int sum=0;
    for(int i=0; i<B; i++){
        for(int j=0; j<B; j++){
            sum+=A[i][j];
        }
    }
    
    //****************
    int temp=sum;
    int mx=sum;
    
    for(int i=0; i<=n-B; i++){
        mx=max(sum,mx); // overall max
        for(int j=B; j<n; j++){ // column mei move krte hue
            int x1=0,x2=0;
            if(i>0){
                x1=C[i-1][j];
                x2=C[i-1][j-B];
            }
            temp = temp + (C[i+B-1][j]-x1) - (C[i+B-1][j-B]-x2); //N1
            mx = max(temp, mx); // row ka max
        }
        if(i+B<n){
            sum = sum - R[i][B-1] + R[i+B][B-1];  //Row change ke time ka updation h so j will be constant na
            temp=sum;
        }
    }
    
    return mx;