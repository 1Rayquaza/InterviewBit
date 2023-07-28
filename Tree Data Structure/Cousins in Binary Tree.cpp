
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A->val == B) return ans;
    queue<TreeNode*> q;
    q.push(A);
    int flag = 0;
    
    while(!q.empty()){           
        int n = q.size();
        
        while(n--){ // queue ko traverse kr rhe hain (har level mei jitne bhi elements hain)
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left && tmp->left->val == B) flag = 1;  
            // either of l/r makes flag 1 so only one considered, however loop goes on for all cousins
            else if(tmp->right && tmp->right->val == B) flag = 1;
            else{
                if(tmp->left)  q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }  
          
        if(flag == 1){
            while(!q.empty()){
                TreeNode* temp = q.front();
                q.pop();
                ans.push_back(temp->val);
            }
        }    
    }
    return ans;
}

/* maybe Level order traversal 'cause cousins are on same level, just need to delete the sibling tho
I need to find the level first

ummm, create a map on every level and store l/r data alongside so we know which value to ignore 
or just find the level then traverse later */

      