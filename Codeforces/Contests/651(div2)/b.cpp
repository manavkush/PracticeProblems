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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[2*n];
        vi vodd,veven;

        re(i,2*n)
        {
            cin>>a[i];
            if(a[i]%2)
            {
                vodd.push_back(i+1);
            }
            else veven.push_back(i+1);
        }
        int codd,ceven;
        codd=vodd.size();
        ceven=veven.size();
        if(ceven==0)
        {
            vodd.pop_back();
            vodd.pop_back();
        }
        else if(codd%2==0)
        {
            veven.pop_back();
            veven.pop_back();
        }
        else 
        {
            vodd.pop_back();
            veven.pop_back();
        }
        
        for(auto x=0;x<veven.size();x=x+2)
        {
            cout<<veven[x]<<" "<<veven[x+1]<<endl;
        }
        for(auto x=0;x<vodd.size();x=x+2)
        {
            cout<<vodd[x]<<" "<<vodd[x+1]<<endl;
        }

    }
}