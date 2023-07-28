string Solution::solve(string A, int B) {
    int n=A.size();
    map<int, int> m;
    char c=A[0];
    int st=0;
    int ct=0;
    
    for(int i=0; i<n; i++){
        if(A[i]==c){
            ct++;
        }
        else{   //har letter ka count store kr liya
            m[st]=ct;   //ye previous value push ho rhi hai BUT what about the last one
            ct=1;
            st=i;
            c=A[i];
        }
    }
    m[st]=ct;   //above else ke baad last element jiske baad loop ends, usko bhi push karana hai
    
    // for(auto x:m){
    //     cout << x.first << " " << x.second << endl;
    // }
    
    string ans;
    for(int i=0; i<n; ){
        if(m[i] != B){
            ans.push_back(A[i]);
            i++;
        }
        else{
            i+=B;
        }
    }
    
    return ans;
}
