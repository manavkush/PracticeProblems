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

int main()
{
    FIO;
    string str;
    cin>>str;
    int n=str.size();
    int x=1;
    int y=1;
    re(i,n)
    {
        if(str[i]=='0')
        {
            if(x%2)
            {
                cout<<"1 1"<<endl;
                x++;
            }
            else
            {
                cout<<"3 1"<<endl;
                x++;
            }
        }
        else
        {
            if(y==1)
            {
                cout<<"1 3"<<endl;
                y++;

            }
            else if(y==2)
            {
                cout<<"2 3"<<endl;
                y++;

            }
            else if(y==3)
            {
                cout<<"3 3"<<endl;
                y++;
            }
            else
            {
                cout<<"4 3"<<endl;
                y=1;
            }
            
        }
    }
}