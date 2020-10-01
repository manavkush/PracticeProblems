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

// Either the string should be composed of one character only
// Or there should be an even length string consisting of only 2 characters in alternating manner

int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        int len=0;
        for(auto i='0';i<='9';i++)              
        for(char j='0';j<='9';j++)
        {
            int turn, count;
            turn=count=0;
            for(char x:s)
            {
                if(x==i && turn==0)
                {
                    count++;
                    turn=1;
                }
                else if(x==j && turn==1)
                {
                    count++;
                    turn=0;
                }
            }
            if(i == j)                  // Condition when both of the digits are same ie the string is made of one digit only
                len=max(len,count);
            else
            {
                if(count&1)                 // Condition if count is odd
                    count--;
                len=max(len,count);
            }
            
        }
        cout<<n-len<<endl;
    }
}