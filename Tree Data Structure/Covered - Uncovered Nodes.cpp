long Solution::coveredNodes(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    long c = 0;  // covered
    long uc = 0;
    long sum = 0;
    while(!q.empty()){
        int n = q.size();
        
        int d;
        if(n==1) d = q.front()->val;
        else d = q.front()->val + q.back()->val;    // for uncovered values
        uc += d;    // updating uncovered values
        
        sum = 0;
        while(n--){     // construct levels and add appropriately
            TreeNode* tmp = q.front();
            q.pop();
            sum += tmp->val;    // current queue ka sum
            if(tmp->left)  q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }      
        c += (sum - d);  
    }
    // cout << c << " " << uc << " ";
    return abs(c - uc);
}


/* READ QUESTIONS PROPERLY !!
right and left BOUNDARY nodes are called uncovered nodes, rest are covered nodes
Boundary nodes: Right and left view elements :)
Level order traversal to the rescue :D front and back elements of a level

WRONG: find total sum by Traversal, find boundary sum separately, perform arithematic operations for ans
*/
