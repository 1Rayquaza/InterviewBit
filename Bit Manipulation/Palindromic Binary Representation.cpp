int convert(string &s){
    int num = 0;
    
    for(auto it : s){
        num = num * 2 + (it - '0');
    }
    return num;
}

int Solution::solve(int n) {
    // BFS - Graph-like ?.. yupp hehe
    if(n == 1) return 1;
    n--; // "1" being done, n-1 more to go
    
    queue<string> q;
    q.push("11");
    int ans;
    
    while(!q.empty()){
        string tmp = q.front();
        q.pop();
        n--;
        
        if(n == 0){
            ans = convert(tmp);
            break;
        }
        
        int tn = tmp.size();
        int mid = tn/2;
        
        if(tn % 2 == 0){
            string s0 = tmp, s1 = tmp;
            s0.insert(mid, "0");
            s1.insert(mid, "1");
            q.push(s0);
            q.push(s1); 
        }
        
        else{
            string ch(1, tmp[mid]);     // convert char to string 
            string s2 = tmp;
            s2.insert(mid, ch);
            q.push(s2);
        }
    }
    
    return ans;
}

