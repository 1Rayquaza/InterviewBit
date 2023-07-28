#include <bits/stdc++.h>

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int fuel = accumulate(A.begin(), A.end(), 0);
    int reqd = accumulate(B.begin(), B.end(), 0);
    if(fuel < reqd) return -1;
    
    int avl = 0;
    int start = 0;
    for(int i=0; i<n; i++){
        avl += A[i];
        
        if(B[i] > avl){
            start = i+1;
            avl = 0;    // i+1 mei apne aap add hojayega next iteration mei
        }
        
        else avl -= B[i];
    }
    // starting point can be any !
    
   return start;
}

// we were able to reach x, x+1 .. anyway, if anything we had surplus from earler, so update point to what we cannot reach !