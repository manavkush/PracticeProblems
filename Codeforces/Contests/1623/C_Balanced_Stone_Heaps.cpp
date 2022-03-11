// Author: $%U%$
// Date: $%D%$/$%M%$/$%Y%$

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minpq;
typedef priority_queue<pii> maxpq;
const int mod = 1000000007;

/*
    We had to maximize the minimum element of the array.
    Whenever there is maxmin or minmax types of questions,
    we try to use binary search for those.

    Also for the question we had to reverse the question 
    and start from the back. '
    Two conditions need to be met for any heap when iterating: 
    i) The d can be at max(a[i]/3) ie d <= a[i]/3;
    ii) The final value( a[i] - 3d + add[i] >= x)\

    From these two we see that d <= min(a[i]/3, (a[i]-add[i]-x)/3)
*/

bool checker(vi &a,int x) {
    int n = a.size();
    vi add(n, 0);
    if(a[n-1] < x) return false;

    for(int i=n-1;i>=2;i--) {
        if(a[i] + add[i] < x) return false;
        int d = min(a[i]/3, (a[i]+add[i]-x)/3);
        add[i] -= d*3;
        add[i-1] += d;
        add[i-2] += 2*d;
    }
    if(a[0] + add[0] < x || a[1] + add[1] < x) return false;
    return true;
}
void solve() {
    int n;
    cin>>n;
    vi a(n);
    re(i,n) cin>>a[i];
    
    int low = 1, high = 2e9;
    while(low+1<high) {
        int mid = (low+high)/2;
        if(checker(a, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout<<low<<endl;
}
int32_t main()
{
    FIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();    
    }
}
