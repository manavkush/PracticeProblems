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
//We calculate the product such that multiplying the numbers gives greater than or equal to the given number
//We store the frequency in an array "a"
//We then print the characters it's frequency times
int main()
{
    FIO;
    lli n;
    cin>>n;
    lli a[10];
    re(i,10)
        a[i]=1;
    string str="codeforces";
    lli prod=1;
    lli itr=0;
    while(prod<n)
    {
        itr=itr%10;
        prod/=a[itr];
        a[itr]++;
        prod*=a[itr];
        itr++;
    }
    //re(i,10)
    //    cout<<a[i]<<" ";
    //cout<<endl;
    re(i,10)
    {
        for(int j=0;j<a[i];j++)
            cout<<str[i];
    }

}