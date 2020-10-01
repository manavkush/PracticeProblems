#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int lli;
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
#define re1(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
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


int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        string s,p;
        cin>>s>>p;
        int n=s.size();
        int n1=p.size();
        map<char,int> m1;
        map<char,int> m;
        string ans;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        for(int i=0;i<n1;i++)
        {
            m1[p[i]]++;
        }
        int i=0;
        int cs=0;
        while(i<n1)
        {
            if(p[i]==p[0])
                i++;
            else
                break;
        }
        if(i==n1)
            cs=0;
        else if(p[i]-'a'<p[0]-'a')
        {
            
            cs=1;
        }
        // __print(m);
        // cout<<endl;
        // __print(m1);
        // cout<<endl;
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            char ch=itr->first;
            int num=itr->second;
            if(m1.find(ch)==m1.end())   // If letter is not common
            {
                re(i,num)
                {
                    ans+=ch;
                    itr->second--;
                }
                continue;
            }
            else if(ch!=p[0])   //If letter's common but isn't first letter 
            {
                int num1=m1.find(ch)->second;
                re(i,num-num1)
                {
                    ans+=ch;
                    itr->second--;
                }
                continue;               
            }
            else if(ch==p[0])   // Letter common & first letter
            {
                if(cs==1)
                {
                    re(i,n1)
                    {
                        ans+=p[i];
                        m[p[i]]--;
                        m1[p[i]]--;
                    }
                    re(i,itr->second)
                    {
                        ans+=ch;
                    }
                    continue;
                }
                else
                {
                    int num1=m1.find(ch)->second;
                    re(i,num-num1)
                    {   
                        ans+=ch;
                        itr->second--;
                    }
                    re(i,n1)
                    {
                        ans+=p[i];
                        m[p[i]]--;
                        m1[p[i]]--;
                    }

                }
                
            }            
        }
        // __print(m1);
        // cout<<endl;
        // __print(m);
        // cout<<endl;
        cout<<ans;
        cout<<endl;
        m1.clear();
        m.clear();
        

    }
}