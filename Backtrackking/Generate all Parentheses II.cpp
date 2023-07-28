void generate(int open, int close, vector<string> &ans, string &tmp){
    if(open > close) return;    // close remaining! since parameters denote avl. brackets
    // close remaining less implies more no. of closed bracketsin ans, i.e. invalid
    if(open == 0 && close == 0){
        ans.push_back(tmp);
        return;
    }
    if(open > 0){   // *** must else MLE
        tmp.push_back('(');
        generate(open-1, close, ans, tmp);
        tmp.pop_back();
    }
    
    if(close > 0){
        tmp.push_back(')');
        generate(open, close-1, ans, tmp);
        tmp.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int A) {
    // we got A '(' and A ')', and we need to generate all valid Parenthesis
    // In a recursive problem, always think from the middle, find what you'd do in the ith step and proceed
    vector<string> ans;
    string tmp;
    generate(A, A, ans, tmp);
    return ans;
}
