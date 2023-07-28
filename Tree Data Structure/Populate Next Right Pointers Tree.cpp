void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    q.push(A);
    
    while(!q.empty()){
        int n = q.size();
        
        while(n--){
            TreeLinkNode* tmp = q.front();  // * mtlb pass by referance so originally mei change ho rha
            q.pop();
            if(n==0) tmp->next == NULL;
            else tmp->next = q.front();
            
            if(tmp->left)  q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
    }
}

/* Kinda seems like Level order traversal
Note: Recursion has memory overhead and does not qualify for constant space.
Queue :D
*/