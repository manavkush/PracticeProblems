#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
        FASTIO;
        int n,temp,q;
        set<int> s;
        set<int, greater<int> > p;
        cin>>n;
        int max=1;
        re(i,n)
        {
                cin>>temp;
                if(s.find(temp)!=s.end())
                        p.insert(temp);
                else
                s.insert(temp);
        }
        max=*--s.end();
        cin>>q;
        re(i,q)
        {
                cin>>temp;
                if(temp>max)
                {
                        max=temp;
                        s.insert(temp);
                }
                else if(temp<max)
                {
                        if(s.find(temp)!=s.end())
                                p.insert(temp);
                        else s.insert(temp);
                }
                cout<<s.size()+p.size()<<endl;
        }
        for(auto itr=s.begin();itr!=s.end();itr++)
                cout<<*itr<<" ";
        for(auto itr=p.begin();itr!=p.end();itr++)
                cout<<*itr<<" ";
}
