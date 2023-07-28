string leftJustify(int i, int j, vector<string> &A, int L){
    string result = "";
    for(int k=i; k<j; k++){
        result += A[k];
        if(k != j-1){
            result += " ";
        }
    }
    
    while(result.size() < L){
        result += " ";
    }
    
    return result;
}

string middleJustify(int i, int j, vector<string> &A, int L, int lineLength){
    int remainingSpaces = L - lineLength;
    int numberOfWords = j-i;
    int spaceNeeded = numberOfWords - 1;
    int spaces = remainingSpaces / spaceNeeded;
    int extraSpaces = (remainingSpaces % spaceNeeded);
    
    string result = "";
    for(int k=i; k<j-1; k++){   // k < j-1 and not j why ??
        result += A[k];
        
        int actualSpaces = spaces + (extraSpaces > 0 ? 1 : 0);
        extraSpaces--;
        
        for(int idx = 0; idx < actualSpaces; idx++){
            result += " ";
        }
    }
    
    result += A[j-1];   // j-1 here hehe
    return result;
}  

vector<string> Solution::fullJustify(vector<string> &A, int L) {
    int n = A.size();
    int i = 0;
    vector<string> result;
    
    while(i < n){
        int j = i+1;
        int lineLength = A[i].size();
        while(j < n && (lineLength + A[j].size() + (j - i) <= L)){
            lineLength += A[j].size();
            j++;
        }
        
        // int diff = L - lineLength;
        int numberOfWords = j - i;
        
        if(numberOfWords == 1 || j >= n){
            result.push_back(leftJustify(i, j, A, L));
        }
        else{
            result.push_back(middleJustify(i, j, A, L, lineLength));
        }
        
        i = j;  // i points to the word we're looking at
    }
    
    return result;
}  


// What must be ## shall be.    ## 
// What must be be ## shall be.    ## 