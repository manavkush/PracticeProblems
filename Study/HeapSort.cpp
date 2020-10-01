#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
void max_heapify(int arr[],int n,int i)
{
        int left=2*i, right=2*i+1;
        int largest;
        if(left<=n&&arr[i]<arr[left])
                largest=left;
        else largest=i;
        if(right<=n&&arr[largest]<arr[right])
                largest=right;
        if(largest!=i)
        {
                swap(arr[largest],arr[i]);
                max_heapify(arr,n,largest);
        }
}
void build_max_heap(int a[],int n)
{
        for(int i=n/2;i>0;i--)
        {
                max_heapify(a,n,i);
        }
}
void heapsort(int a[],int n)
{
        build_max_heap(a,n);
        for (int i=n;i>=2;i--)
        {
                swap(a[i],a[1]);
                n--;
                max_heapify(a,n,1);
        }
}

int main()
{
        FASTIO;
        int n;
        cin>>n;
        int a[n+1];
        re1(i,1,n)
                cin>>a[i];
        heapsort(a,n);
        for (int i=1;i<=n;i++)
        {
                cout<<a[i]<<" ";
        }
}
