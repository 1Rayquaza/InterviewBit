int Solution::nTriang(vector<int> &A) {
    int n=A.size(), m=1e9+7;
    if(n<3) return 0;
    sort(A.begin(), A.end());
    int c=0;
    
    // *** easy to go reverse since if small no. satisfies inequality then bigger no. will satisfy too
    // fix i from end and j from beginning amd k in mid 
    for(int i=n-1; i>=2; i--){
        int j=0, k=i-1;
        while(j<k){
            if(A[j]+A[k] > A[i]){   // ***
                c = ((c%m) + (k-j)%m)%m;  
                k--;
            }
            else j++;
        }
    }
    return c;
}
// O(N) or O(NlogN)
// sum of length of 2 sides must be > length of the third side
// possible triangles in eg. are : 1,1,1  1,2,2  1,2,2  1,2,2
// 1e7/1e8 times loop chalta h max
// for A < B < C, they form a triangle if they follow the triangle inequality i.e. A + B > C
// Ai < Aj < Ak  where i<j<k , for every i and j we need to find how many k's  
// 2 elements are fixed so need to see the third one according to the rules
  