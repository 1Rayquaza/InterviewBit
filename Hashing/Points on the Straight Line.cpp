int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n=A.size();
    if(n<3) return n;
    unordered_map<double, int> mp;
    int mx = 0;
    for(int i=0; i<n; i++){
        mp.clear(); // *** calculating no. of points with same slope value passing through P1, need a new map for every point
        for(int j=0; j<n; j++){
            if(j != i){            
                double dy = B[i]-B[j];
                double dx = A[i]-A[j];
                double m = (double)INT_MAX;
                if(dx != 0){
                    m = (double)dy/dx;
                }
                if(mp.find((double)m) == mp.end()){
                    mp[m] = 2;  // 2 pts. contribute to a slope for the first time, then ++
                }
                else mp[m]++;
                mx = max(mx, mp[m]);
            }
        }
    }
    return mx;
}         

/*  two points always lie on the same line, we need to find how many more can fit to max.
    points with same Abscissa or ordinate lie on the same line
    how to see for pts besides this ??? (which have same slope)
    find pair-wise slope, store in map, and see which slope has max. value(no. of points) */
