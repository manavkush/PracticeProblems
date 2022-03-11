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

vector<project> projects; // list of projects
vector<contributor> contrib;

map<pair<string, int>, vector<string>> avlb; // maps <role with levl> to <people>
map<project, int> proj_avlb;
map<pair<string, int>, int> working;
vector<pair<string, vector<string>>> finalans;

bool comp(project& p1, project& p2)
{
    // First criteria is score
    if (p1.score != p2.score)
        return p1.score > p2.score;
    // Second criteria is no of days (lower better)
    return p1.days < p2.days;
}

bool operator<(const project& t1, const project& t2)
{
    return (t1.score < t2.score);
}

int32_t main(int argc, char* args[])
{
    FIO;
    fin.open(args[1]);
    fout.open("output.txt");
    fin >> c >> p;
    for (int i = 0; i < c; i++) {
        // Loop for each contributer
        contributor x;
        fin >> x.name >> x.num_skills;
        // fout<<x.name<<x.num_skills<<endl;;

        for (int j = 0; j < x.num_skills; j++) {
            role y;
            fin >> y.name >> y.level;
            x.skills.push_back(y);

            for (int k = 1; k <= y.level; k++)
                avlb[{ y.name, k }].push_back(x.name);
        }
        contrib.push_back(x); // push into vector
    }

    for (int i = 0; i < p; i++) {
        project x;
        fin >> x.name >> x.days >> x.score >> x.bestbefore >> x.num_roles;
        for (int j = 0; j < x.num_roles; j++) {
            role y;
            fin >> y.name >> y.level;
            x.roles.push_back(y);
        }
        projects.push_back(x);
        proj_avlb[x] = 1;
    }

    // sorted projects
    sort(all(projects), comp);

    vector<vector<project>> completion(200005); // completion[i] denotes projects completed on that day
    map<project, vector<string>> associates; // maps an ongoing project to it's developers
    map<string, bool> nameUsed; // to check if a person is working
    int time_ = 0;

    // MAIN TIME LOOP
    for (time_ = 0; time_ < 10000; time_++) {
        // deinitializing completed projects
        while (!completion[time_].empty()) {
            project x = completion[time_].back();
            completion[time_].pop_back();
            // iterating on associated people
            for (auto& dev_name : associates[x]) {
                nameUsed[dev_name] = false;
            }
        }

        // initializing new proj0
        bool ok = false;
        for (int i = 0; i < p; ++i) {
            vector<string> temp; // Storing the names of the people
            if (proj_avlb[projects[i]] == 1) {
                for (auto it : projects[i].roles) {
                    ok = false;
                    for (auto ss : avlb[{ it.name, it.level }]) {
                        if (nameUsed[ss] == false) {
                            nameUsed[ss] = true;
                            temp.push_back(ss);
                            ok = true;
                            break;
                        }
                    }
                    if (ok == false) {
                        break;
                    }
                }

                if (ok) {
                    finalans.push_back({ projects[i].name, temp });

                    associates[projects[i]] = temp;
                    proj_avlb[projects[i]] = 0;
                    completion[time_ + projects[i].days].push_back(projects[i]);
                } else {
                    for (int i = 0; i < temp.size(); ++i) {
                        nameUsed[temp[i]] = false;
                    }
                }
            }
        }
    }
    fout << finalans.size() << endl;
    for (auto projs : finalans) {
        fout << projs.first << endl;
        for (auto names : projs.second) {
            fout << names << " ";
        }
        fout << endl;
    }
}