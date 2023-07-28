TreeNode* construct(vector<int> &pre, vector<int> &ino, int preIdx, int inS, int inE, unordered_map<int, int> &m){
    if(inS > inE){
        return NULL;
    }
    if(preIdx >= pre.size()){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(pre[preIdx]);
    if(inS == inE){
        return root;
    }
    
    int rootIdx = m[root->val];
    int ct = rootIdx - inS + 1;
    
    // for(int i=inS; i<=inE; i++){
    //     ct++;
    //     if(root->val == ino[i]){
    //         rootIdx = i;
    //         break;
    //     }
    // }
    // In case of left skewed BT, TC will be O(N2) 'cause, for every node we'll be searching N elements
    // so using hashing will make Tc O(1) for this operation making overall TC O(N)
    
    root->left =  construct(pre, ino, preIdx+1, inS, rootIdx-1, m);
    root->right = construct(pre, ino, preIdx+ct, rootIdx+1, inE, m);
    return root;
}

// TC: O(N);
// SC: O(N) for storing TreeNode and some memory for stack memory, some for map
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[B[i]] = i;
    }
    return construct(A, B, 0, 0, n-1, m);
}

/*  Preorder - N L R
    Inorder  - L N R
    Till root val , elements are in left subtree of root 

    e.g.
    Inorder:  1 0 2 3 4 8 10 11 12 13
    Preorder: 4 2 0 1 3 10 8 12 11 13
    Preorder first ele is 4, i.e. root, next ele is 2 that lies to root left in Inorder, next ele is 0 i.e.
    to the left of 2, next ele is 1 that lies to left of 0, 
    then next ele is 3 that lies right to 2
    
    
*/