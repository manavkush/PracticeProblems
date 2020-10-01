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

//     For any a, b, if b > a, a%b = a. Additionally, if a ≥ b > , a%b = a - b.
//     Let's add 5·10^5 to the whole array, loop over a(i) (in order), and mod prefix i with a(i) - i
int main()
{
    FASTIO;
    int n;
    cin>>n;
    int a[n],temp;
    re(i,n)
    {
        cin>>temp;
        a[i]=temp+500002;
    }
        cout<<n+1<<"\n";
        cout<<1<<" "<<n<<" "<<500002<<"\n";
     re(i,n)
    {
        cout<<2<<" "<<i+1<<" "<<(a[i]-i)<<"\n";
    }
}
