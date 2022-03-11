// Author: $%U%$
// Date: $%D%$/$%M%$/$%Y%$

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
//===================================DEBUG TEMPLATE=================================================
void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x)
{
    int f = 0;
    cerr << '{';
    for (auto& i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
//====================================DEBUG TEMPLATE==============================================
int longest_palindrome_prefix(string& s)
{
    /**
     * The LPS computation can determine, at any given index i in a string S, the maximum suffix length that
     * make up a suffix equal to the prefix. For example: S = "acexxxaceyyy": at S[6], S[7], and S[8] will be
     * marked with "1", "2", and "3" respectively because "a", "ac", and "ace" at this points in the string
     * make up substrings whose suffixes equal to the string's prefix. This computation can be done in one
     * linear scan of the string in O(N) time, using a secondary integer array in O(N) space.
     *
     * For our purpose in finding the longest palindrome prefix of a string, the idea is simple:
     * if we reverse the string, then appending it to the original string (after a special marker),
     * the palindromic prefix will show up at the end of the compound string! If we then apply the above algorithm,
     * by the end of the linear scan, we'll have a number that correspond to the maximum suffix length of
     * the entire compound string, which correspond to a suffix = prefix. And since a palindromic prefix, when
     * reversed and appended, will show up as the suffix, we will conveniently have computed the maximum
     * length of the palindromic prefix!
     *
     * For example: consider the string S = "abbaaax". The longest palindrome prefix is "abba".
     * 1. Create S' = "abbaaax#xaaabba"
     * 2. Compute LPS: lps[] = { 0,  0,  0,  1,  1,  1,  0,  0,  0,  1,  1,  1,  2,  3,  4 }
     *            from  S'[] = {'a','b','b','a','a','a','x','#','x','a','a','a','b','b','a'}
     * 3. The last element of LPS, 4, is our longest palindrome prefix length!
     */
    string kmprev = s;
    std::reverse(kmprev.begin(), kmprev.end());
    string kmp = s + "#" + kmprev;

    vector<int> lps(kmp.size(), 0); // lps[i] = longest suffix length for substring kmp[0..i] where the suffix == prefix
    for (int i = 1; i < (int)lps.size(); ++i) {
        int prev_idx = lps[i - 1];

        while (prev_idx > 0 && kmp[i] != kmp[prev_idx]) {
            prev_idx = lps[prev_idx - 1];
        }

        lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
    }

    // after KMP's LPS preprocessing, the last index of the LPS array will contain the longest palindrome prefix' length!
    return lps[lps.size() - 1];
}
void solve()
{
    string s, t;
    cin >> s;
    t = s;
    reverse(all(t));
    if (t == s) {
        cout << 0 << endl;
        return;
    }
    int common = 0;
    int n = s.length();

    int i = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[j]) {
            common++;
        } else {
            j++;
        }
    }
    cout << common << endl;
}
int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
