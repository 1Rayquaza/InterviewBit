int Solution::maxProduct(const vector<int> &a) {
    int n = a.size();
    int max1 = a[0];
    int min1 = a[0];
    int ans = max(max1,min1);
    for(int i=1;i<n;i++){
        if(a[i]<0){
            swap(max1,min1);
        }
        max1 = max(max1*a[i],a[i]);
        min1 = min(min1*a[i],a[i]);
        ans = max(max1,ans);
    }
    return ans;
}

