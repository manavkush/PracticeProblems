#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        // int cnt;
        if(a<b) {
            for(int i=0;i<2*a;i++) {
                if(i&1) cout<<0;
                else cout<<1;
            }
            // cout<<string(a, "10");
            cout<<string(b-a, '1');
        } else {
            // cout<<string(b, "01");
            for(int i=0;i<2*b;i++) {
                if(i&1) cout<<1;
                else cout<<0;
            }
            cout<<string(a-b, '0');
        }
        cout<<endl;
    }
}