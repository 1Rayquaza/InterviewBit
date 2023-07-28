vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {    
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    
    q.push(A);
    q.push(NULL);   // for flagging when we need to push a level
    if(A==NULL) return ans;
    int flag = 0;
    vector<int> v;
    
    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();

        if(tmp != NULL){
            v.push_back(tmp->val);
            if(tmp->left)  q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        
        else if(tmp == NULL){
            if(flag == 0) ans.push_back(v);
            else if(flag == 1){
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
            v.clear();
            flag = !flag;
            if(!q.empty()) q.push(NULL);
        }
        
    }
    
   
    return ans;
}

/* Zigzag order traversal: level order traversal but one time right, one time left and so one
we can make 2 level order traversal fns. and call each other hehe
WAITOOO, store normally but push in ans with reverse order
*/