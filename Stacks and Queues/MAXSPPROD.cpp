// LSV: i>j and A[j]>A[i] i.e. left side mei greater element but if multiple present then maximum j i.e. closest greater 
// RSV: i<j and A[j]>A[i] i.e. right side mei greater element, if multiple then nearest j

// READ QUESTION CAREFULLY !!! wasted an hour because of this :)) not again ughhh

int Solution::maxSpecialProduct(vector<int> &A) {
    int n=A.size();
    int m=1e9+7;

    // Nearest greater element to the left
    vector<int> L(n);
    stack<pair<int, int>> s1;
    for(int i=0; i<n; i++){
        // if(s1.size()==0){
        //     L[i]=-1;
        // }
        // else if(s1.size()!=0 && s1.top().first>A[i]){
        //     L[i]=s1.top().second;
        // }
        // else if(s1.size()!=0 && s1.top().first<=A[i]){
        //     while(s1.size()!=0 && s1.top().first<=A[i]){
        //         s1.pop();
        //     }
        //     if(s1.size()==0) L[i]=-1; 
        //     else L[i]=s1.top().second;
        // }
        
        while(s1.size()!=0 && s1.top().first<=A[i]){
            s1.pop();
        }
        if(s1.size()==0) L[i]=-1; 
        else L[i]=s1.top().second;
        
        s1.push({A[i], i});
    }
    
    // Nearest greater element to the right
    vector<int> R(n);
    stack<pair<int, int>> s;
    for(int i=n-1; i>=0; i--){
        // if(s.size()==0){
        //     R[i]=-1;
        // }
        // else if(s.size()!=0 && s.top().first>A[i]){
        //     R[i]=s.top().second;
        // }
        // else if(s.size()!=0 && s.top().first<=A[i]){
        //     while(s.size()!=0 && s.top().first<=A[i]){
        //         s.pop();
        //     }
        //     if(s.size()==0) R[i]=-1; 
        //     else R[i]=s.top().second;
        // }
        
        // DAMNNNNNNNNNNNNNNN WHY didn't this occur to me ear;lier !!!!
        while(s.size()!=0 && s.top().first<=A[i]){
            s.pop();
        }
        if(s.size()==0) R[i]=-1; 
        else R[i]=s.top().second;
        
        s.push({A[i], i});
    }
     
    long long mx=0;
    for(int i=0; i<n; i++){
        if(L[i]==-1 || R[i]==-1){
            continue;
        }
        else{
            mx = max(mx, L[i]*1LL*R[i]);    // Typecasting important
        }
    }
    
    // take mod in the end cause taking mod may change the out of range values to smaller values
    return mx%m;
}
