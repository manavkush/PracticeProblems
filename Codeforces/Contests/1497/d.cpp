#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        for(int i=4;i<=k;i++) {
            cout<<1<<" ";
            n--;
        }
        if(n&1) {
            cout<<1<<" "<<(n-1)/2<<" "<<(n-1)/2<<endl;
            // continue;
        } else {
            if((n/2)&1) {
                cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<endl;
            } else {
                cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
            }
        }
    }
}