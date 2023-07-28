vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    unordered_set<string> st(dict.begin(), dict.end());
    queue<vector<string>> q;
    q.push({start});    
    
    vector<string> usedOnLevel;
    usedOnLevel.push_back({start});
    
    vector<vector<string> > ans;
    
    int level = 0;
    while(!q.empty()){
        vector<string> v = q.front();
        q.pop();
        
        if(v.size() > level){
            level++;
            for(auto it: usedOnLevel){
                st.erase(it);
            }
        }
        
        if(end == v.back()){
            if(ans.size() == 0){
                ans.push_back(v);
            }
            else if(ans[0].size() == v.size()){
                ans.push_back(v);
            }
        }
        
        string word = v.back();
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    v.push_back(word);
                    q.push(v);
                    
                    usedOnLevel.push_back(word);
                    v.pop_back();
                }
            }
            
            word[i] = original;
        }
    }
    
    return ans;
}
