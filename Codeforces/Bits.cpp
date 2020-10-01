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
#define re(i,n)   for(int i=0;i<n;i++)
#define it(i,a)        for(auto i=a.begin();i!=a.end();i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)


int main()
{
    int n;
    cin>>n;
    bool a[n]={false};
    bitset<23> pan[n];
    re(i,n)
        cin>>pan[i];
 //       re(i,n)
  //      cout<<pan[i]<<"\n";
  //      cout<<endl;
    re(i,n-1)
    {
        re1(j,i+1,n-1)
        {
            if((pan[j]&pan[i])==0)
                {
                    a[j]=1;
                    a[i]=1;
                 }
        }
    }
    re(i,n)
    cout<<(a[i] ? 1: -1)<<endl;

    return 0;
}
