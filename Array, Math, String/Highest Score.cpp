int Solution::highestScore(vector<vector<string> > &A) {
    int N=A.size();
    map<string, pair<int, int> > mp;    //bob ke corresponding, we're storing sum(of marks) and count(for avg.)
    
    for(int i=0; i<N; i++){
        string key=A[i][0];    //student name
        pair<int,int> p;
        if(mp.find(key)==mp.end()){
            p={0,0};
        }
        else{
            p=mp[key];
        }
        mp[key]={p.first+stoi(A[i][1]),++p.second}; //stoi is string to integer fn., AND, p.first mei null value hai
    }
    
    
    int mx=0;
    //upar pair p h, neeche auto p h, both DIFFERENT
    //auto it; - NOOO, initialise it first, No need 'cause simplified way below
    for(auto p:mp){ //iterating every mp value <"Bob",<170,2>>
        int avg=(p.second.first)/(p.second.second); // p.second is <170,2>
        mx=max(mx, avg);
    }
    return mx;
                                     
}
                                                                                                            