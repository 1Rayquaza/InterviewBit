struct TrieNode{
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isEnd = false;
    }    
};

void insert(TrieNode* root, string &tmp){
    for(int i=0; i<tmp.size(); i++){
        int index = tmp[i] - 'a';
        if(root->children[index] == NULL){
            root->children[index] = new TrieNode();
        }
        root = root->children[index];
    }
    
    root->isEnd = true;
}

bool check(TrieNode* root, string &word){
    for(int i=0; i<word.size(); i++){
        int index = word[i] - 'a';
        if(root->children[index] == NULL){
            return false;
        }
        root = root->children[index];
    }
    return (root->isEnd);
}

int goodWords(TrieNode* root, string &review){
    int c = 0; 
    for(int i=0; i<review.size();){
        string word;
        while(review[i] != '_' && i<review.size()){
            word.push_back(review[i]);
            i++;
            if(i==review.size()) break;
        }
        if(check(root, word)) c++;
        i++;
        word.clear();
    }
    return c;
}

bool comp(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.first == p2.first){
        return (p1.second < p2.second); // < is asc., > is desc.
    }    
    else{
        return (p1.first > p2.first);    // > st false and order change
    }   
}

vector<int> Solution::solve(string A, vector<string> &B) {
    TrieNode* root = new TrieNode();
    
    for(int i=0; i<A.size();){
        string tmp;
        while(A[i] != '_' && i<A.size()){
            tmp.push_back(A[i]);
            i++;
            if(i==A.size()) break;
        }
        insert(root, tmp);
        i++;
        tmp.clear();
    }
    
    vector<pair<int, int>> res;
    for(int i=0; i<B.size(); i++){
        res.push_back({goodWords(root, B[i]), i});
        // cout << res[i].first << " " << res[i].second << " ";
    }
    
    sort(res.begin(), res.end(), comp);
    
    vector<int> ans;
    for(int i=0; i<res.size(); i++){
        ans.push_back(res[i].second);
    }
    return ans;
}
