#define ll long long int
int Solution::pow(int x, int n, int d) {
    // Modulo operator to the rescue else ... forever multiplication :))
    // Modular exponentiation ..
    if(d==1) return 0;
    if(x == 0) return 0;
       ll ans = 1, y = x%d;
     // a%b or (a % b + b) % b for negative no.
    while(n>0){
        if(n&1){
            ans = (ans*y)%d;  // but only multiply with ans if the bit is actually there in power
        }
        y = (y*y)%d;    // keep updating x^0, x^1, x^2 ... but
        n=n>>1;
    }
    if(ans < 0){
        ans = (d - abs(ans) % d);
        return ans;
    }
    return ans;
}