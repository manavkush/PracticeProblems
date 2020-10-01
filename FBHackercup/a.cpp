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
    ofstream myfile;
    myfile.open("answerA.txt", ios::out);

    FIO;
    int t;
    cin>>t;
    re(z,t) 
    {
        int n;
        cin>>n;
        string in,og;
        cin>>in>>og;
        myfile<<"Case #"<<(z+1)<<":"<<endl;
        string s(n,'N');
        re(i,n)
        {
            string temp=s;
            temp[i]='Y';
            if(og[i]=='N')
            {
                myfile<<temp<<endl;
                continue;
            }
            FORD(j,i-1,0)
            {
                if(in[j]=='N')
                    break;
                temp[j]='Y';
                if(og[j]=='N')
                    break;
            }
            re1(j,i+1,n-1)
            {
                if(in[j]=='N')
                    break;
                temp[j]='Y';
                if(og[j]=='N')
                    break;
            }
            myfile<<temp<<endl;
        }

    }
}