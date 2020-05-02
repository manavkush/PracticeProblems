#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
    string str[9];
    re(i,9)
          cin>>str[i];

      str[0][0]=str[1][0];
      str[1][3]=str[2][3];
      str[2][6]=str[0][6];
      str[3][1]=str[4][1];
      str[4][4]=str[5][4];
      str[5][7]=str[3][7];
      str[6][2]=str[7][2];
      str[7][5]=str[8][5];
      str[8][8]=str[6][8];

      for(int i=0;i<9;i++)
          cout<<str[i]<<"\n";
    }
}
