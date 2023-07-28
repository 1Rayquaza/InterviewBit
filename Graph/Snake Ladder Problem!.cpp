int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    unordered_map<int, int> mp;
    for(auto it: A) mp[it[0]] = it[1];
    for(auto it: B) mp[it[0]] = it[1];
    
    queue<pair<int, int>> q;
    q.push({1, 0}); // num, moves
    
    vector<int> vis(101, 0);
    vis[1] = 1;
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        int num = it.first;
        int moves = it.second;
        
        if(num == 100) return moves;
        
        for(int i=1; i<=6; i++){
            int newNum = num + i;
            if(newNum <= 100 && !vis[newNum]){
                // if snake/ladder affects position
                if(mp.find(newNum) != mp.end()){ 
                    q.push({mp[newNum], moves + 1});
                    vis[newNum] = 1;
                }
                
                else{   // no effect
                    q.push({newNum, moves + 1});
                    vis[newNum] = 1;
                }
            }
        }
    } 
    return -1;
}
