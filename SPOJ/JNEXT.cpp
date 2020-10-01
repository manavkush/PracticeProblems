#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef stack <int> si;
typedef stack <lli> slli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
        FASTIO;
        int t;
        vi v;
        si s;           // stack
        cin>>t;
        while(t--)
        {
                int n;
                cin>>n;

                int b[n],idx=-2,i;
                while(!s.empty())
                {
                        s.pop();
                }
                re(i,n)                                 // Entering the elements of the array
                        cin>>b[i];

                int flag=0;
                // ==================================
                re(i,n)
                {
                        if(s.empty())
                                s.push(i);
                        else
                        {
                                while(b[i]>b[s.top()])
                                {
                                        flag=1;
                                        idx=i;
                                        s.pop();
                                        if(s.empty())
                                                break;
                                }
                                s.push(i);
                         }
                }
                //==================================================================================
                if(!flag)
                {
                        cout<<-1<<endl;
                        continue;
                }

               for(i=n-1;i>=idx;i--)
                {
                        if(b[i]>b[idx-1])
                        {
                                swap(b[i],b[idx-1]);
                                break;
                        }
                }
                for(i=0;i<idx;i++)
                {
                        cout<<b[i];
                }
                for(i=n-1;i>=idx;i--)
                {
                        cout<<b[i];
                }
                cout<<endl;
        }

}
