struct TrieNode{
    TrieNode* children[2];
    bool isEnd;
    
    TrieNode(){
        children[0] = NULL;
        children[1] = NULL;
        isEnd = false;
    }
    
};

int mxXOR(TrieNode* root, int num){
    int mx = INT_MIN;
    int ans = 0;
    for(int i=31; i>=0; i--){
        int index = ((num>>i) & 1);
        if(root->children[!index]){
            root = root->children[!index];
            ans = (ans | (1<<i));
        }
        else root = root->children[index];
    }
    return ans;
}

void insert(TrieNode* root, int num){
    for(int i=31; i>=0; i--){
        int index = ((num>>i) & 1);
        if(root->children[index] == NULL){
            root->children[index] = new TrieNode();
        }
        root = root->children[index];
    }
    root->isEnd = true;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    TrieNode* root = new TrieNode();
    for(int i=0; i<A.size(); i++){
        insert(root, A[i]);
    }
    
    int mx = INT_MIN;
    for(int i=0; i<B.size(); i++){
        mx = max(mx, mxXOR(root, B[i]));
    }
    return mx;
}

// XOR will be max. when max. mismatch 0^1/1^0 = 1
// ek ka tree bnakr, doosre ke elements se check krte jao