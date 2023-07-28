// O(h) space, store left only, then find right as required instead of storing all
stack<TreeNode*> s;

BSTIterator::BSTIterator(TreeNode *root) {
    while(root != NULL){
        s.push(root);
        root = root->left;  // stored the path then keep changing it for O(h) memory soln.
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return (!s.empty());
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* next = s.top();
    s.pop();
    int ans = next->val;
    
    // however we did NOT consider the existence of a right node midway so need to check -
    if(next->right){
        next = next->right;
        while(next != NULL){
            s.push(next);
            next = next->left;
        }
    }
    
    return ans;
}


// O(N) space Ezzzzz
queue<int> s;   // why queue but nor stack ??
BSTIterator::BSTIterator(TreeNode *root) {
    if(root == NULL) return;
    // O(N) memory tho :/
    BSTIterator(root->left);
    s.push(root->val);
    BSTIterator(root->right);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    // depends on the next()
    if(s.size() > 0) return 1;
    else return 0;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int tmp = s.front();
    s.pop();
    return tmp;
}