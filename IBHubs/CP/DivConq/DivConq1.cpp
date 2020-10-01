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
int maxcss(int a[],int low,int high)
{
    int mid=(low+high)/2;
    int ls,rs;
    ls=rs=INT8_MIN;
    int sum=0;
    for(int i=mid;i>=low;i--)
    {
        sum+=a[i];
        if(sum>ls)
            ls=sum;
    }
    sum=0;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        if(sum>rs)
            rs=sum;
    }
    return ls+rs;
}
int maxsub(int a[],int low, int high)
{
    if(low==high)
        return a[low];
    int mid=(low+high)/2;
    int lss=maxsub(a,low,mid);
    int rss=maxsub(a,mid+1,high);
    int css=maxcss(a,low,high);

    return max(max(lss,rss),css);
}


int main()
{
    FIO;
    int n;
    cin>>n;
    int a[n];
    re(i,n)
        cin>>a[i];
    cout<<maxsub(a,0,n-1);
}