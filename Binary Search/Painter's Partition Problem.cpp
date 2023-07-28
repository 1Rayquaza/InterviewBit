#define ll long long
bool isPossible(ll mid, int P, vector<int> &A){  // mid is the time
    int n=A.size();
    int m=1e7+3;
    int p=1;    //atleast 1 painter se shuru krenge
    ll sum=0;
    // Let say we're given A, P, T and we've to tell if it can be completed within T time then how???
    // With P painters; if all painted and P<n then true
    for(int i=0; i<n; i++){
        if(A[i] > mid) return false;    // max. time se bada single painted area lmao
        sum += A[i];    // MUST be painted in order given
        if(sum > mid){
            sum = A[i];
            p++;    // ab doosra painter chaiye 
        }
    }
    return p<=P;
}

// *** Let's say T=1, then last mei multiply krdenge actual T se
int Solution::paint(int P, int T, vector<int> &A) {
    // N=1e5, upto O(NlogN) allowed
    // Like ship conveyer problem where weights=length, and here, we're given the ship capacity and
    // have to find the days i.e. reverse of the original q.
    // One board needs to be completed by only one painter
    // if P > n, [*max_element(A.begin(), A.end())]*T would be answer
    int n=A.size();
    int m=1e7+3;
    int mx = *max_element(A.begin(), A.end());   //sbse time taking board
    if(P >= n){ //har board pr ek painter + kuch velle
        return mx*T;    // this will be min. time if more boards are there
    }
    
    int total_board = 0;
    for(int i=0; i<n; i++){
        total_board += A[i];
    }
    // P < n, toh ab strategically painters allot krne, better to get big ones done first
    // sort(A.begin(), A.end());
    // reverse(A.begin(), A.end());
    long long int lo=mx, hi=INT_MAX;
    while(hi - lo > 1){
        ll mid = (lo+hi)/2;
        // let say we've a fn. which tells us if it's possible to paint the boards in time mid
        // FF...FTT..T we've to find the first T
        if(isPossible(mid, P, A)){
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    if(isPossible(lo, P, A)) return ((lo%m)*(T%m))%m; // min. time reqd.
    else return ((hi%m)*(T%m))%m;
    
}

/* The q. is pretty much same as ship conveyer except that time/unit is confusing, 
Pehle A[i] package carry krna h, then A[i+1] ... (in time T) by P painters
Since, order should be maintained Painters allot krte jao until khtm na hojaaye
Agr khtm hone tk pehle Painters */