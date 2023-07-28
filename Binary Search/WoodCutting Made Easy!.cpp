bool woodNeed(vector<int> &A, int B, int h){
    long long wood=0;
    for(int i=0; i<A.size(); i++){ // poore A pr check krna hai
        if(A[i]>h){
            wood = wood + (A[i]-h);
        }
    }
    return wood >= B;
}

int Solution::solve(vector<int> &A, int B) {
    /* Predicate function T T T T ... T F F ... function, we need to find the last H where it would be True i.e. 
    (min. wood requirement satisfied) Binary Search to the rescue :D 
    but we need O(N) and sorting will take O(NlogN) so what to do, editorial says I'm good :/ */
    int n=A.size();
    sort(A.begin(), A.end());
    long long lo=0, hi=1e9, mid;    // hi for max. height
    while(hi - lo > 1){
        // Let say there's a fn. which tell us if this height will give T or F, now what ..? so-
        mid = (lo+hi)/2;
        if(woodNeed(A, B, mid)){
            lo = mid;
        }
        else{
            hi = mid-1; //F ke pehle jaana hi pdega
        }
    }
    if(woodNeed(A, B, hi)) return hi;
    else return lo;
}
