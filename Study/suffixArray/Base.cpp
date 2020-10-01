#include<bits/stdc++.h>
using namespace std;
#define re(i,n) for(int i=0;i<n;i++)
int main()
{
    string str;
    int i;
    cin>>str;
    str+='$';
    int n=str.size();
    vector<int> p(n),c(n);

    vector<pair<char,int>> v(n);
    for(int i=0;i<n;i++)
    {
        v[i]={str[i],i};
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
        p[i]=v[i].second;
    
    c[p[0]]=0;
    for(i=1;i<n;i++)
    {
        if(v[i].first==v[i-1].first)
            c[p[i]]==c[p[i-1]];
        else c[p[i]]=c[p[i-1]]+1;
    }
    int k=0;
    while((1<<k)<n)
    {
        vector<pair<int,int>,int> a(n);
        re(i,n)
        {
            a[i]={c[i],c[(i+(1<<0))%n]};
        }

    }
}