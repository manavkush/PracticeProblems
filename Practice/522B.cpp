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
    string str;
    cin>>str;
    int n=str.size();
    int row,flag,col,i,ast,j;
    row=(n+19)/20;
    col= (n+row-1)/row;
    ast=row*col-n;
    int cnt=0;
    cout<<row<<" "<<col<<"\n";
    int ind=0;
    for(i=0;i<row;i++)
    {
        flag=0;
        if(cnt<ast)
        {
            cout<<"*";
            flag=1;
            cnt++;
        }
        for(j=0;j<col-flag;j++)
        {
            cout<<str[ind++];
        }
        cout<<"\n";
    }


}
