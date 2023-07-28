#define ll long long
vector<vector<ll>> dp;
vector<vector<ll>> fac;
int m = 1e9+7; 

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

ll mdI(ll b)
{
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}

ll ways(ll n, ll r){
    if(r == 0){
        if(n == 0) return 0;
        else return 1;
    }
    
    if(fac[n][r] != -1){
        return fac[n][r];
    }
    
    if(r == 1){
        return fac[n][r] = n%m;
    }
    
    ll inv = mdI(r)%m;
    
    
    return fac[n][r] = ((((ways(n-1, r-1)%m)*(n%m))%m)*(inv%m))%m;
}

ll solve(ll n, ll h){
    if(n <= 1){
        if(h == 0) return 1;
        else return 0;
    }
    
    if(h==0){
        return 0;
    }
    
    ll ans = 0;
    
    if(dp[n][h] != -1){
        return dp[n][h];
    }
    
    for(int i=1; i<=n; i++){
        ll x = i-1;
        ll y = n-i;
        
        ll tmp = 0;
        for(int j=0; j<h-1; j++){
            tmp = (tmp%m + ((solve(x, j)%m)*(solve(y, h-1)%m))%m)%m;
        }
        
        for(int j=0; j<h-1; j++){
            tmp = (tmp%m + ((solve(y, j)%m)*(solve(x, h-1)%m))%m)%m;
        }
        
        tmp = (tmp%m + ((solve(x, h-1)%m)*(solve(y, h-1)%m))%m)%m;    
        
        ans = (ans%m + ((tmp%m)*(ways(x+y, y)%m))%m)%m;   
    }
    
    return dp[n][h] = ans%m;
}
int Solution::cntPermBST(int n, int h) {
    dp.clear();
    dp.resize(n+1, vector<ll> (h+1, -1));
    
    fac.clear();
    fac.resize(n+1, vector<ll> (n+1, -1));
    
    return solve(1ll*n, 1ll*h)%m;
}
