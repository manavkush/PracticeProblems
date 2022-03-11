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
// #define endl "\n"
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
//=====================DEBUG TEMPLATE=========================
ifstream fin;
ofstream fout;
int c, p; // #contributors, #projects

// A role in a project
struct role {
    string name;
    int level;
};

// A project
struct project {
    string name;
    int days, score, bestbefore, num_roles;
    vector<role> roles;
};

struct contributor {
    string name;
    int num_skills;
    vector<role> skills;
};

vector<project> projects;
vector<contributor> contrib;

int32_t main(int argc, char* args[])
{
    FIO;
    cout << args[1] << endl;
    fin.open(args[1]);
    fout.open("output.txt");
    fin >> c >> p;
    fout << c << " " << p << endl;
    for (int i = 0; i < c; i++) {
        // Loop for each contributer
        contributor x;
        fin >> x.name >> x.num_skills;
        fout << x.name << x.num_skills << endl;
        ;

        for (int j = 0; j < x.num_skills; j++) {
            role y;
            fin >> y.name >> y.level;
            fout << y.name << y.level << endl;
            x.skills.push_back(y);
        }
        contrib.push_back(x); // push into vector
    }

    for (int i = 0; i < p; i++) {
        project x;
        fin >> x.name >> x.days >> x.score >> x.bestbefore >> x.num_roles;
        fout << x.name << x.days << x.score << x.bestbefore << x.num_roles << endl;
        for (int j = 0; j < x.num_roles; j++) {
            role y;
            fin >> y.name >> y.level;
            fout << y.name << y.level << endl;
            x.roles.push_back(y);
        }
        projects.push_back(x);
    }
}