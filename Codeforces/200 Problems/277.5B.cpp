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
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FIO;
    int l,s;
    cin>>l>>s;
    if(s>l*9)
        cout<<"-1 -1"<<endl;
    else if(s==0)
    {
        if(l==1)
            cout<<"0 0"<<endl;
        else cout<<"-1 -1"<<endl;
    }
    else
    {
        int sum2=s;
        int l1=l;
        while(sum2>9)
        {
            cout<<9;
            sum2=sum2-9;
            l1--;
        }
        cout<<sum2<<" ";
        while(l1)
        {
            cout<<0;
            l1--;
        }

            



    }
    
}