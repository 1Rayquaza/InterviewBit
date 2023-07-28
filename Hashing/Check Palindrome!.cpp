int Solution::solve(string A) {
    unordered_map<char,int> m;
    for(auto i:A){
        m[i]++;
    }
    int c=0;
    for(auto i:m){
        if(i.second%2){
            c++;    
        }
        if(c>1){    // incase of odd length, 1 no. can occur once else not palindrome
            return 0;
        }
    }
    return 1;
}
