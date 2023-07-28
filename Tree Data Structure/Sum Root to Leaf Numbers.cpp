void totalsum(TreeNode* A, int tmp, int &sum, int &m){
    if(A == NULL) return;
    tmp = (tmp*10 + A->val)%m;
    
    if(A->left == NULL && A->right == NULL){
        sum = (sum%m + tmp%m)%m;    // Leaf node reached, update sum
        //tmp = tmp/10;   // yahan pr bhi backtrack krna
        return;
    }
        
    if(A->left)  totalsum(A->left,  tmp, sum, m);
    if(A->right) totalsum(A->right, tmp, sum, m);   
    
    //tmp = tmp/10; commented after removing &tmp, only tmp is right 
}
int Solution::sumNumbers(TreeNode* A) {
    int m = 1003;
    int tmp = 0;
    int sum = 0;
    totalsum(A, tmp, sum, m);
    return sum%m;
}

/* using strings can give give overflow during conversion then how ???
How to traverse tree while keeping the number from tree to leaf

I may use a separate fn. for addition of 2 strngs in a mechanical way OR BETTER: x10 with each node and add

763 3 7 9 9 0 -1 -1 2 1 4 3 2 5 2 2 4 8 1 1 4 9 0 -1 8 3 5 2 5 -1 1 6 2 8 1 0 7 3 -1 7 -1 6 6 1 7 1 5 9 4 7 -1 7 -1 -1 -1 6 2 8 7 8 1 5 9 0 4 6 -1 -1 5 6 -1 2 1 8 2 5 5 -1 4 -1 1 9 1 4 3 5 7 4 -1 -1 0 6 7 5 -1 2 1 7 1 9 0 2 5 4 -1 -1 -1 -1 -1 8 2 2 -1 -1 -1 -1 -1 2 -1 3 9 4 8 8 6 4 7 2 5 7 1 -1 9 5 3 8 0 4 -1 -1 5 5 7 2 -1 -1 -1 8 0 4 4 5 5 7 -1 -1 5 6 3 -1 9 1 9 -1 8 -1 -1 9 -1 -1 8 -1 -1 -1 -1 -1 -1 -1 -1 -1 6 7 3 -1 1 8 -1 -1 1 8 -1 -1 -1 8 0 0 5 6 -1 -1 0 -1 9 -1 5 -1 6 6 -1 6 2 6 5 -1 -1 7 3 1 6 -1 7 6 -1 -1 6 -1 3 9 -1 -1 -1 0 -1 2 -1 0 -1 7 3 5 -1 8 2 0 6 8 7 3 9 0 1 0 -1 -1 -1 0 8 7 2 9 -1 6 6 6 -1 2 3 2 -1 -1 1 1 4 8 -1 2 0 -1 -1 -1 -1 -1 -1 1 3 6 -1 -1 -1 -1 5 4 1 7 7 -1 -1 -1 -1 -1 -1 0 8 0 -1 5 5 -1 7 3 -1 -1 1 -1 -1 -1 7 9 4 -1 4 -1 -1 -1 -1 -1 -1 -1 -1 -1 0 0 5 5 -1 -1 -1 2 6 8 1 -1 0 -1 6 -1 0 -1 -1 -1 -1 -1 -1 6 8 2 -1 4 2 -1 1 -1 -1 -1 2 1 0 2 7 8 -1 1 -1 -1 3 4 -1 -1 -1 -1 -1 5 -1 -1 8 2 -1 -1 -1 -1 2 8 -1 3 -1 8 6 3 -1 -1 -1 8 6 4 -1 -1 -1 -1 5 -1 -1 -1 -1 -1 -1 9 4 -1 -1 -1 -1 -1 -1 -1 2 2 7 3 9 -1 -1 9 -1 -1 -1 -1 6 -1 3 8 -1 -1 -1 -1 -1 -1 -1 3 -1 -1 -1 -1 -1 -1 -1 -1 4 -1 2 -1 -1 -1 -1 2 -1 -1 1 9 1 -1 -1 2 5 1 -1 -1 4 2 -1 -1 -1 7 6 3 8 2 8 -1 -1 0 -1 -1 3 1 -1 -1 5 -1 -1 9 -1 2 -1 0 -1 -1 -1 8 -1 -1 8 -1 -1 0 -1 0 -1 7 -1 -1 1 4 -1 9 5 3 -1 -1 -1 2 3 -1 -1 -1 6 7 -1 0 6 -1 -1 -1 -1 -1 5 -1 -1 -1 5 -1 -1 -1 -1 -1 4 8 3 -1 -1 9 5 -1 -1 -1 9 0 -1 -1 -1 -1 -1 -1 -1 -1 4 -1 7 -1 -1 -1 -1 -1 -1 -1 4 0 -1 8 1 -1 5 -1 0 -1 -1 -1 -1 -1 1 1 0 -1 8 6 -1 -1 -1 -1 -1 -1 3 5 9 4 1 9 -1 -1 -1 -1 -1 6 -1 -1 -1 -1 -1 -1 5 -1 -1 9 -1 -1 0 -1 -1 -1 -1 0 1 -1 3 -1 8 -1 1 -1 -1 -1 -1 2 5 6 2 6 -1 6 6 4 -1 9 -1 -1 -1 -1 5 8 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 5 -1 7 -1 -1 -1 -1 9 4 2 1 8 -1 -1 -1 3 4 -1 -1 -1 -1 -1 -1 -1 5 -1 -1 -1 -1 -1 4 -1 9 -1 -1 -1 3 -1 -1 3 -1 -1 7 4 1 -1 -1 -1 -1 -1 -1 -1 -1 7 8 -1 9 0 -1 -1 -1 2 6 -1 8 -1 -1 -1 -1 -1 2 -1 4 2 -1 -1 6 8 -1 -1 -1 -1 -1 4 -1 -1

*/
