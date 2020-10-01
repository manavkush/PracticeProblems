#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i, n) for (int i = 0; i < (n); i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minpq;
typedef priority_queue<pii> maxpq;
const int mod = 1000000007;

// Binary Search over real numbers
// There are n ropes, you need to cut k pieces of the same length from them. Find the maximum length of pieces you can get.
int n, k;
bool solve(double m, vector<int> &a)
{
    int sum = 0;
    for (auto x : a)
    {
        sum += (floor(x / m));
    }
    return sum >= k;
}

int32_t main()
{
    FIO;
    cin >> n >> k;
    vi a(n);
    re(i, n)
    {
        cin >> a[i];
    }
    cout << fixed;
    double l = 0;                        // This is good ie we can can k pieces of length 0
    double r = *max_element(all(a)) + 1; // This is bad as we cannot cut even 1 piece of this length

    // l and r are the length boundaries
    // We are iterating over the lengths

    re(i, 100)
    {
        double m = (l + r) / 2;
        if (solve(m, a))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l;
}