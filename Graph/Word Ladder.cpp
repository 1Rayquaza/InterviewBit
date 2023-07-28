int Solution::solve(string startWord, string targetWord, vector<string> &wordList) {
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == targetWord){
            return steps;
        }
        
        // replace each character of ‘word’ with char from a-z then check if ‘word’ exists in wordList.
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                // check if it exists in the set and push it and erase so aage long path mei include nhi ho
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    
    return 0;
}
