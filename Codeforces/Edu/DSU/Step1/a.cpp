#include<bits/stdc++.h>
using namespace std;

class dsu
{
    private:
        int n;
        vector<int> p;
        vector<long long> size;
    public:
        dsu(int n) 
        {
            this->n = n;
            
            p.resize(n+1, 0);
            size.resize(n+1, 0);

            for(int i=1;i<=n;i++) {
                p[i] = i;
            }
            for(int i=1;i<=n;i++) {
                size[i] = 1;
            }
        }
        int find_(int a);
        void union_(int a, int b);
        void print_p() {
            for(auto x: p) {
                cout<<x<<" ";
            }
        }
        void print_size() {
            for(auto x: size) {
                cout<<x<<" ";
            }
        }
};

void dsu::union_(int a, int b) {
    a = find_(a);
    b = find_(b);
    if(a!=b) {
        if(size[a]<size[b]) {
            swap(a,b);
        }
        p[b] = p[a];
        size[a] += size[b];
    }
}

int dsu::find_(int a) {
    if(p[a] != a) {
        p[a] = find_(p[a]);
    }
    return p[a];
}


int main() {
    int n,m;
    cin>>n>>m;
    dsu d(4);
    while(m--) {
        string str;
        int a,b;
        cin>>str;
        cin>>a>>b;
        if(str=="union") {
            d.union_(a,b);
        } else {
            string res = (d.find_(a) == d.find_(b) ? "YES" : "NO");
            cout<<res<<endl;
        }
    }
    // d.print_p();
    // cout<<endl;
    // d.print_size();
}