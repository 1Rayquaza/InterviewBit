void generate(vector<int> &A, vector<int> tmp, vector<vector<int>> &ans){
    if(tmp.size() == A.size()){ // all elements covered
        ans.push_back(tmp);
        return;
    }
    
    for(int j=0; j<A.size(); j++){  
        // har  baar poora array traverse kr rhe, jo element nhi aaya wo aa jayega
        if(find(tmp.begin(), tmp.end(), A[j]) == tmp.end()){
            tmp.push_back(A[j]);
            generate(A, tmp, ans); 
            tmp.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> tmp;
    
    generate(A, tmp, ans);  
    sort(ans.begin(), ans.end());
    return ans;
}

/* 
We need ALL the elements of the array. Now, let's say tmp = [3, 1] atm, we'll traverse the whole array 
again to see which element are remaining and push them.

*** we don't know how 3,1 got there, we need to think how to push the next element ***

We don't need any current(int i) parameter since we need to go through entire array and push whatever 
is already not there

*/