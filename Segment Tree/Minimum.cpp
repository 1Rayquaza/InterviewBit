#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct segTree{
    int size;
    vector<int> values;
    
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        values.assign(2*size, 0);
    }
    
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            values[x] = v;
            return;
        }
        
        int m = (lx + rx)/2;
        if(i < m){
            set(i, v, 2*x + 1, lx, m);
        }
        else{
            set(i, v, 2*x + 2, m, rx);
        }
        
        values[x] = min(values[2*x + 1], values[2*x + 2]); 
    }
    
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    
    int calc(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) return INT_MAX;
        if(lx >= l && rx <= r) return values[x];
        
        int m = (lx + rx)/2;
        ll s1 = calc(l, r, 2*x + 1, lx, m);
        ll s2 = calc(l, r, 2*x + 2, m, rx);
        
        return min(s1, s2);
    }
    
    int calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    segTree st;
    st.init(n);
    
    for(int i=0; i<n; i++){
        int v;
        cin >> v;
        st.set(i, v);
    }
    
    while(m--){
        int op;
        cin >> op;
        
        if(op == 1){
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << st.calc(l, r) << endl;
        }
    }
    
    return 0;
}