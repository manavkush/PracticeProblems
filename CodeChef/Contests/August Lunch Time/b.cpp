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
//===================================DEBUG TEMPLATE=================================================
void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
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


int32_t main()
{
    FIO;
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vi r(n);    // Ratings
        re(i,n)
        {
            cin>>r[i];
        }
        vi c[n];    // Rating changes after m months for each player
        re(i,n)
        {
            c[i].resize(m);
            re(j,m)
            {
                cin>>c[i][j];
            }
        }
        //==================================== Solving ==========================================
        vi peakratingmonth(n);
        vi peakrankingmonth(n);
        vi peakrankings(n,INT_MAX);     // Peak ranks of each player
        // Calculating the peak ratings for each player
        re(i,n)     // Players
        {
            int peak=0;
            int peakmonth=0;
            int curr=r[i];
            re(j,m)         // Iterating over all the months
            {
                curr=curr+c[i][j];
                if(peak<curr)
                {
                    peak=curr;
                    peakmonth=j;
                }
            }
            peakratingmonth[i]=peakmonth;
        }
        // Now peakrankingmonth is settled

        // Rating calculation of each month (precalculation)
        vector<int> ratings [n];
        re(i,n)
            ratings[i].resize(m);
        
        re(i,n)     // For each player
        {
            re(j,m) // For each month
            {
                if(j==0)
                    ratings[i][j]=r[i]+c[i][0];
                else
                {
                    ratings[i][j]=ratings[i][j-1]+c[i][j];
                }
            }
        }
        //=============================
        // re(i,n)
        // {
        //     debug(ratings[i]);
        // }

        re(j,m) // Iterating over each month
        {
            vector<int> vec;
            re(i,n)
            {
                vec.pb(ratings[i][j]);
            }
            sort(all(vec));
            re(i,n)
            {
                int pos=distance(upper_bound(all(vec),ratings[i][j]),vec.end());
                // cout<<i<<" "<<pos<<endl;
                if(pos<peakrankings[i])
                {
                    peakrankings[i]=pos;
                    peakrankingmonth[i]=j;
                }
            }
            vec.clear();
        }
        // debug(peakratingmonth);
        // debug(peakrankingmonth);
        int count=0;
        re(i,n)
        {
            if(peakratingmonth[i]!=peakrankingmonth[i])
            {    
                count++;
            }
        }
        cout<<count<<endl;

    }
}