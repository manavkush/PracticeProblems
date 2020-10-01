#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define REP(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
     lli t,n,i,k;
    cin>>t;
    unordered_set<lli> sett;
    map <lli,lli> m;
    while(t--)
    {
        cin>>n>>k;
        lli arr[n],count;

        REP(i,n)
        {
            cin>>arr[i];
            if(arr[i]>k)
            {
                sett.insert(i);
            }
        }

        for(i=0;i<n/2;i++)
        {
            if(sett.find(i)!=sett.end()||sett.find(n-1-i)!=sett.end())
                continue;
            m[arr[i]+arr[n-1-i]]++;
        }
        auto x = std::max_element(m.begin(), m.end(), m.value_comp());
        val=x->second;

        for(i=0;i<n/2;i++)
        {
            if(arr[n-1-i]>k&&arr[i]>k)
                {
                    count=count+2;

                    //arr[i]=1;
                    //arr[n-1-i]=x->second-1;
                    continue;
                }
            else if(arr[i]>k||arr[n-i-k]>k)
            {
                    count=count+1;
            }
            else if(arr[i]+arr[n-i-1]==x)
            {
                ;
            }
            else if(arr[i]>val||arr[n-i-1]>val)



        }

    }
}
