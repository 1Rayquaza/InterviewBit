struct TrieNode{
    TrieNode* children[26];
    bool isEnd;
    int words;
    
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        words = 0;
        isEnd = false;
    }
};

void unique(TrieNode* root, string &key, string &tmp){
    for(int i=0; i<key.size(); i++){
        int index = key[i] - 'a';
        if(root->words == 1) break;
        
        tmp.push_back(key[i]);
        root = root->children[index];
    }
}

void insert(TrieNode* root, string &key){
    for(int i=0; i<key.size(); i++){
        int index = key[i] - 'a';
        if(root->children[index] == NULL){
            root->children[index] = new TrieNode();
        }
        root->words++;
        root = root->children[index];
    }
    root->isEnd = true;
}

vector<string> Solution::prefix(vector<string> &A) {
    TrieNode* root = new TrieNode();
    
    for(int i=0; i<A.size(); i++){
        insert(root, A[i]);
    }
    
    vector<string> ans;
    for(int i=0; i<A.size(); i++){
        string tmp;
        unique(root, A[i], tmp);
        ans.push_back(tmp);
    }
    return ans;
}
