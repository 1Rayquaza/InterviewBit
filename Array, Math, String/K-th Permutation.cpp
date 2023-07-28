int firstDigitIndex(int N, long &k){ //'cause we need to keep updating k as per sub-sets
    //position of first digit mil jayega
    if(N==1){
        return 0;   //we're returning indices
    }
    /* k/(n-1)! was leading to 1-based indexing position of element in the set, but set and vector are 
    zero-based so issuesss, hence we did k-- */
    long motu = N-1;
    while((k >= motu) && N>2){  //n-- -> n-1 --> 0 hojayegi 1 value rkhne pr
        N--;
        motu = motu*(long)(N-1);
    }
    long index = k/motu;
    k = k%motu;
    return index;
}

vector<int> Solution::findPerm(int N, long k) {
    //recursive problem but set will keep updating
    k--;    // 0-based indexing
    set<int> s;
    for(int i=0; i<N; i++){
        s.insert(i+1);  //forming 1st permutation
    }
    
    vector<int> ans;
    for(int i=N; i>0; i--){
        auto it = s.begin();
        int index = firstDigitIndex(i, k);
        advance(it, index); //advanced algorith
        ans.push_back((*it));
        s.erase(it);  //it -> delete index, *it -> deletes value
    }
    
    return ans;
}
