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
    lli n,a,b,i;
    cin>>n;
    unordered_set <lli> set,set2;
    unordered_set<lli> ::iterator itr;
     cin>>a>>b;
     if(a%2==0||b%2==0)
           set.insert(2);

     while (a % 2 == 0)
            a = a/2;

    for ( i = 3; i <= sqrt(a); i = i + 2)
    {
         while (a % i == 0)
        {
            set.insert(i);
            a = a/i;
        }
    }
    if (a > 2)
      set.insert(a);

    while (b % 2 == 0)
         b = b/2;

    for ( i = 3; i <= sqrt(b); i = i + 2)
    {
         while (b % i == 0)
        {
            set.insert(i);
            b = b/i;
        }
    }
     if (b > 2)
            set.insert(b);

    for(i=1;i<n;i++)
    {
          cin>>a>>b;
          for(itr=set.begin();itr!=set.end();itr++)
          {
                if(a%(*itr)==0||b%(*itr)==0)
                {
                      set2.insert(*itr);
                }
          }
          set.clear();
          set=set2;
          set2.clear();
    }
    if(set.empty())
             cout<<-1;
    else cout<<*set.begin();

}
