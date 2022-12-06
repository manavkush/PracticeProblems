#include<bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin>>tt;
    for(int i = 0;i<tt;i++) {
        string s;
        cin>>s;
        cout<<"Case #"<<(i+1)<<": ";
        int sum = 0;
        int n = s.length();
        for(int i=0;i<n;i++) {
            sum = (sum + (s[i]-'0'))%9;
        }
        if(sum==0) {
            cout<<s<<endl;
        } else {
            // cout<<"*";
            int dig = 9-sum;
            bool toprint = 1;
            for(int i=0;i<n;i++) {
                if(toprint and (s[i]-'0'>dig)) {
                    toprint = 0;
                    cout<<dig<<s[i];
                } else {
                    cout<<s[i];
                }
            }
            if(toprint) {
                cout<<dig;
            }
            
            cout<<endl;
        }
    }
}