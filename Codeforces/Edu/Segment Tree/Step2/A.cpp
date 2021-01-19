#include<bits/stdc++.h> 
using namespace std;

struct item {
    long long seg,pref,suff,summ;
};

struct segtree {
    
    int size;   // We need closest power of 2 greater than or equal to n
    vector<item> values;

    item NEUTRAL_ELEMENT = { 0, 0, 0, 0 };
    // If we add this element to any other element the result would be the same.

    item merge(item a, item b) {
        return {
            max(a.seg, max(b.seg, a.suff+b.pref)),
            max(a.pref, a.summ + b.pref),
            max(b.suff, b.summ + a.suff),
            a.summ + b.summ
        };
    }

    item single(int v) {
        if(v>0) {
            return {v, v, v, v};
        } else {
            return {0, 0, 0, v};
        }
    }

    void init(int n) {
        size=1;
        while(size<n) size*=2;
        values.resize(2*size);
    }

    void build(vector <int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if (lx < (int)a.size()) {
                values[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);

        values[x] = merge(values[2*x+1], values[2*x+2]);
    }
    void build(vector <int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x] = single(v);
            return;
        }
        int m = (lx + rx)/2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    item calc(int l, int r, int x, int lx, int rx) {
        if(l>=rx || lx>=r) {
            return NEUTRAL_ELEMENT;
        } 
        if(l<=lx && r>=rx) {
            return values[x];
        }
        int m = (lx+rx)/2;
        return merge(calc(l,r,2*x+1,lx,m), calc(l,r,2*x+2,m,rx));
    }
    item calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        int v;
        cin >> a[i]; 
    }
    st.build(a);
    cout<<st.calc(0,n).seg<<endl;
    // cout<<st.values[0].seg<<endl;
    while(m--) {
        int i, v;
        cin >> i >> v;
        st.set(i, v);
        cout<<st.calc(0,n).seg<<endl;
        // cout<<st.values[0].seg<<endl;
    }
    return 0;
}