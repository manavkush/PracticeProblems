#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
bool comp( pair<int,int> p1,pair<int,int>p2)
{
    return (abs(p1.first)+abs(p1.second))<(abs(p2.second)+abs(p2.first));
}
int main()
{
    //FIO;
    int n;
    cin>>n;
    vector<pair<int,int> > p;
    int a,b;
    re(i,n)
    {
        cin>>a>>b;
        p.pb(mp(a,b));
    }
    sort(p.begin(),p.end(),comp);
    lli count=0;
    re(i,n)
    {
        if(p[i].first==0||p[i].second==0)
        {
            count+=4;
        }
        else count+=6;
    }
    cout<<count<<endl;
    re(i,n)
    {
        if(p[i].first>0)
            printf("1 %d R\n",p[i].first);
        if(p[i].first<0)
            printf("1 %d L\n",-p[i].first);
        if(p[i].second>0)
            printf("1 %d U\n",p[i].second);
        if(p[i].second<0)
            printf("1 %d D\n",-p[i].second);
        cout<<2<<endl;
        if(p[i].first>0)
            printf("1 %d L\n",p[i].first);
        if(p[i].first<0)
            printf("1 %d R\n",-p[i].first);
        if(p[i].second>0)
            printf("1 %d D\n",p[i].second);
        if(p[i].second<0)
            printf("1 %d U\n",-p[i].second);
        cout<<3<<endl;

    }


    // for(auto it=p.begin();it!=p.end();it++)
    // {
    //     cout<<it->first<<" "<<it->second;
    //     cout<<endl;
    // }
}