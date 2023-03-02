// we need to perform the MAH thingy for each row now
// Max Area Histogram
int maxArea(vector<int> &A){    // for each row, O(M)
    int n=A.size();
    vector<int> L(n);
    stack<pair<int, int>> l;
    for(int i=0; i<n; i++){
        if(l.size()==0){
            L[i]=-1;
        }
        else if(l.size()!=0 && l.top().first<A[i]){
            L[i]=l.top().second;
        }
        else if(l.size()!=0 && l.top().first>=A[i]){
            while(l.size()!=0 && l.top().first>=A[i]){
                l.pop();
            }
            if(l.size()==0) L[i]=-1;
            else L[i]=l.top().second;
        }
        l.push({A[i], i});
    }
    
    vector<int> R(n);
    stack<pair<int, int>> r;
    for(int i=n-1; i>=0; i--){
        if(r.size()==0){
            R[i]=n;
        }
        else if(r.size()!=0 && r.top().first<A[i]){
            R[i]=r.top().second;
        }
        else if(r.size()!=0 && r.top().first>=A[i]){
            while(r.size()!=0 && r.top().first>=A[i]){
                r.pop();
            }
            if(r.size()==0) R[i]=n;
            else R[i]=r.top().second;
        }
        r.push({A[i], i});
    }
    
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        int area = A[i]*(R[i]-L[i]-1);
        mx = max(mx, area);
    }
    return mx;
}

/* similar to max. area histogram q. but different histograms on each level on each level
e.g. 1 1 1      1 1 1   3
     0 1 1      0 2 2   4
     1 0 0      1 0 0   1
*/
int Solution::maximalRectangle(vector<vector<int> > &B) {
    int n=B.size();
    int m=B[0].size();
    
    // Pre-computation of height for all levels
    vector<vector<int>> v(n, vector<int> (m)); // Create a vector containing "n" vectors each of size "m"
    for(int j=0; j<m; j++){
        int c=0;    // har column ke liye starting with zero
        for(int i=0; i<n; i++){
            if(B[i][j]==0){
                v[i][j]=0;
                c=0;
            }
            else{
                c++;
                v[i][j]=c;
            }
        }
    }

    // vector v with bottom row information ready
    // now we've to call fn. maxArea on this and each subsequent row
    // to make the subsequent rows we'll +1 in presence of 1 or make it 0 when encountered with 0
    int mx = INT_MIN;
    for(int i=n-1; i>=0; i--){
        int area = maxArea(v[i]);
        mx = max(mx,area);
    }
    return mx;
}


