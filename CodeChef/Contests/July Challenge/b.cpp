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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
int dig(int k)
{
    int sum=0;
    while(k)
    {
        sum+=k%10;
        k=k/10;
    }
    return sum;
}
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int chef=0;
        int morty=0;
        int n;
        cin>>n;
        re(i,n)
        {
            int a,b;
            cin>>a>>b;
            if(dig(a)>dig(b))
                chef++;
            else if(dig(a)<dig(b))
                morty++;
            else {
                chef++;
                morty++;
            }
        }
        if(chef>morty)
            cout<<0<<" "<<chef<<endl;
        else if(chef<morty)
            cout<<1<<" "<<morty<<endl;
        else cout<<2<<" "<<chef<<endl;
    }
}