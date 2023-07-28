bool isPalindrome(string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i] != s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}

void generatePalindrome(string &A, vector<vector<string>> &ans, vector<string> &tmp, int i){
    if(i == A.size()){
        ans.push_back(tmp);
        return;
    }
    
    // we need to generate from any i to end of string
    for(int j=i; j<A.size(); j++){  // i - partition ke baad ka pehla index, j se length decide hogi
        string str = A.substr(i, j-i+1);    // aise saarei substring aa jayenge
        if(isPalindrome(str)){
            tmp.push_back(str);
            generatePalindrome(A, ans, tmp, i+str.size());  
            // i+str.size() = j+1 i.e. last element ka next
            tmp.pop_back();
        }  
        // backtrack - abhi jo substring bni usko remove krna, i toh same hi h
                
    }
    
}

// we need to partition string s.t. every part is a palindrome ! 
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string> tmp;
    generatePalindrome(A, ans, tmp, 0);
    // sort(ans.begin(), ans.end()); 'cause j=i se shuru ho rha for loop so apne aap sorted rhega
    return ans;
}
