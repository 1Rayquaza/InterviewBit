#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
    
    // jaise BT mei ->left/->right child hota hai, ||y ismei 26 children hote
    // isEnd indicates the end of word: answer mei 's' pr isEnd true hoga then r ke next NULL pr bhi true hoga
};

bool isEmpty(TrieNode* root){
    for(int i=0; i<26; i++){
        if(root->children[i] != NULL){
            return false;
        }
    }
    return true;
}

TrieNode* deleteKey(TrieNode* root, string &key, int i){
    if(root == NULL) return NULL;
    
    if(i == key.size()){
        if(root->isEnd){
            root->isEnd = false;
        }
        
        if(isEmpty(root)){
            delete (root);
            root = NULL;
        }
        
        return root;
    }
    
    int index = key[i] - 'a';
    root->children[index] = deleteKey(root->children[index], key, i+1);
    
    if(isEmpty(root) && root->isEnd == false){
        delete (root);	// to free memory
        root = NULL;	// agr kisi doosre word ka part nhi toh delete bhi krdo
    }
    return root;
}

bool search(TrieNode* root, string &key){
    
    for(int i=0; i<key.size(); i++){
        int index = key[i] - 'a';
        if(root->children[index] == NULL){
            return false;
        }
        root = root->children[index];
    }
     return (root->isEnd);
}

void insert(TrieNode* root, string &key){
    
    for(int i=0; i<key.size(); i++){
        int index = key[i] - 'a'; 
        if(root->children[index] == NULL){
            root->children[index] = new TrieNode();
        }
        root = root->children[index];
    }
    
    root->isEnd = true;
}

int main() {
    TrieNode* root = new TrieNode();
    vector<string> v = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero" };
                      
    for(int i=0; i<v.size(); i++){
        insert(root, v[i]);
    }
    
    string key = "the";
    deleteKey(root, key, 0);
    cout << search(root, key);
    
}
