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
     lli t,n,i,j,sum=0,temp;
    cin>>t;
    vector<lli > vec;
    while(t--)
    {
        cin>>n;
        cin>>temp;
        vec.push_back(temp);
        j=0;

        for(i=1;i<n; i++ )
        {
            cin>>temp;
            if(vec[ j ]>0&&temp>0)
            {
                if(vec[j]<temp)
                {
                    vec[j]=temp;
                }
            }
            else if(vec[ j ]<0&&temp<0)
            {
                if(vec[j]<temp)
                {
                    vec[j]=temp;
                }
            }
            else
            {
                vec.push_back(temp);
                j++;
            }
        }

        sum=0;
        for(i=0;i<vec.size();i++)
        {
            sum+=vec[i];
        }
        cout<<sum<<"\n";

        vec.clear();
    }
}
