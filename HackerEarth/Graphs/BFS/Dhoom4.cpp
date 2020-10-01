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

bool vis[100005]={false};


int main()
{
    int k,lk;

    cin>>k>>lk;
    int n;
    cin>>n;
    int keyarr[n];
    re(i,n)
    {
        cin>>keyarr[i];
    }
    int movecount=0;
    int currlayer=1;
    int nextlayer=0;

    int flag=0;
    queue<lli> q;
    q.push(k);
    vis[k]=true;
    while (!q.empty())
    {
        lli top=q.front();
        q.pop();
        currlayer--;
        if(top==lk)
        {
            cout<<movecount<<endl;
            flag=1;
            break;
        }
        for(auto x:keyarr)
        {
            lli nkey=(x*top)%100000;
            if(!vis[nkey])
            {
                q.push(nkey);
                vis[nkey]=true;
                nextlayer++;
            }
        }
        if(currlayer==0)
        {
            currlayer=nextlayer;
            nextlayer=0;
            movecount++;
        }
    }
    if(!flag)
    {
        cout<<-1;
    }

}
