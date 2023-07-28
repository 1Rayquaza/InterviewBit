// kinda like subsets generation but need to check sum of elements of a subsets
// Catch: an element can be used unlimited no. of times ***
// Use a no. until it either adds to B or if exceeded, choose next number
void solve(vector<int> &A, int B, vector<int> &tmp, set<vector<int>> &ans, 
    int i, int currSum){   // tmp ko update krte rehna hai
    
    if(currSum > B) return;
    if(currSum == B){
        ans.insert(tmp);
        return;
    }
    if(i == A.size()) return;  //at this place else currSum will not be checked
    
    
    // if A[i] is skipped and next element is includded
    solve(A, B, tmp, ans, i+1, currSum);
    
    // if A[i] is included
    currSum += A[i];
    tmp.push_back(A[i]);
    solve(A, B, tmp, ans, i, currSum);
    currSum -= A[i];
    tmp.pop_back();
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int n=A.size();
    sort(A.begin(), A.end());
    set<vector<int>> ans;
    vector<int> tmp;
    
    solve(A, B, tmp, ans, 0, 0);   // sum is zero atm
    // sort(ans.begin(), ans.end()); set is already sorted, no need for this
    vector<vector<int>> finalAns(ans.begin(), ans.end());
    return finalAns;
}


