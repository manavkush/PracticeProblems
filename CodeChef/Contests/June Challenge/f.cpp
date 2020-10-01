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
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
char rec(int x)
{
    char c;
    cout<<x;
    cin>>c;
    if(c=='E')
        exit(1);
    else return c;
}

void calculate(int low, int high)
{
        char c,c2,c3;
        int mid=(low+high)/2;
        cout<<(low+high)/2;
        cin>>c;
        //-========================================
        if(c=='E')  exit(0);
        //-------------------------------------------
        else if(c=='G')
        {
            cout<<(low+high/2)+1;
            cin>>c2;
            if(c2=='E')
                exit(0);
            
            else if(c2=='G')
            {
                calculate((low+high)/2 +2,high);
            }
            else if(c2=='L')
            {
                cout<<((low+high)/2+2);
                cin>>c3;
                if(c3=='E')
                    exit(0);
                else if(c3=='G')
                {
                    char x;
                    cout<<mid;
                    cin>>x;
                    if(x==c)
                    calculate((low+high)/2+3,high);
                    else calculate(low,mid-1);
                }
                else if(c3=='L')
                {
                    calculate(low,(low+high)/2-1);
                }
            }
        }
        //===============================================
        else if(c=='L')
        {
            cout<<(low+high/2)-1;
            cin>>c2;
            if(c2=='E')
                exit(0);
            
            else if(c2=='L')
            {
                calculate(low,(low+high)/2-2);
            }
            else if(c2=='G')
            {
                cout<<((low+high)/2-2);
                cin>>c3;
                if(c3=='E')
                    exit(0);
                else if(c3=='G')
                {
                    calculate((low+high)/2+1,high);
                }
                else if(c3=='L')
                {
                    char x;
                    cout<<mid;
                    cin>>x;
                    if(x==c)
                    calculate(low,(low+high)/2-3);
                    else calculate(mid+1,high);
                }
            }
        }
}

int main()
{
    FIO;
    int n;
    cin>>n;
    calculate(1,n);
}