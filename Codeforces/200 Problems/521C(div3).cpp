#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int n,i,max,ind;
    cin>>n;             int num[n],num2[n];
   vector <pair<int,int> >  vec;
    long long int sum=0;
    re(i,n)
    {
        cin>> num[i];             //Input
       // num2[i]=num[i];
        sum+=num[i];
        vec.push_back(make_pair(num[i],i));
    }

  sort(vec.begin(),vec.end());

  int idx0=vec[n-1].second;
  int num0=vec[n-1].first;
  int idx1=vec[n-2].second;
  int num1=vec[n-2].first;


    vi v;              //  For Storing
    re(i,n)
    {
        if(i==idx0)
            max=num1;
        else
            max=num0;
        if( 2*max   ==  (sum-num[i]) )
            v.push_back(i);
    }
    cout<<v.size()<<"\n";
    if(v.size()==0)
        return 0;
    re(i,v.size())
        cout<<v[i]+1<<" ";
}
