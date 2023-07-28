vector<int> Solution::solve(vector<int> &A, int B) {
    // Return the largest B elements in any order you like - can be optimised to O(NlogK) using heaps
    // K largest elements - min heap
    int n=A.size();
    priority_queue<int, vector<int>, greater<int>> minH;
    
    for(int i=0; i<n; i++){
        minH.push(A[i]);
        if(minH.size() > B){
            minH.pop();
        }
    }
    vector<int> ans(B);
    for(int i=0; i<B; i++){
        ans[i] = minH.top();
        minH.pop();
    }
    return ans;
}

/* It's not neccesary that the heap is sorted besides the top element, however, the moment we pop the
top element, it heapifies and top element is smallest/largest for sure */