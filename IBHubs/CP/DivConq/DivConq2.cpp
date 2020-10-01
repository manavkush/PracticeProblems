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
string mincom(string str1,string str2)
{
    int i=0;
    string temp;
    for(i=0;(i<str1.size())&&(i<str2.size());i++)
    {
        if(str1[i]==str2[i])
        {
            temp+=str1[i];
        }
        else
            break;
    }
    return temp;
}
string lcp(string str[],int f,int l)
{
    if(f==l)
        return str[f];
    else 
    {
        int mid=(f+l)/2;
        return mincom(lcp(str,f,mid),lcp(str,mid+1,l));
    }
}

int main()
{
    FIO;
    int n;
    cin>>n;
    string str[n];
    int min=0;
    re(i,n)
    {
        cin>>str[i];
    }
    string temp=lcp(str,0,n-1);
    cout<<temp;
    if(temp=="")    cout<<-1;
}