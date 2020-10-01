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

int main()
{
    FIO;
    int n,m,k;
    int i;
    cin>>n>>m>>k;
    int vec[m][m];
    re(i,m)
    {
        re(j,m)
            vec[i][j]=0;
    }

    lli arr[m]={0};
    re(i,n)
    {
        re(j,m)
        {
            int temp;
            cin>>temp;
            //arr[temp-1]+=j;
            vec[temp-1][j]++;
        }
    }
    
    //re(i,m)
    //    cout<<arr[i]<<" ";
    //cout<<endl;

    lli min=100000;
    int minid=-1;
    
    //===============================
    min=0;
    for(i =0;i<m;i++)
    {
        if(vec[i][0]>min)
            {
                min=vec[i][0];
                minid=i;
            }
    }
    cout<<minid+1<<endl;
    int count=0;
    k=k-1;
    int a[m]={0};
    /*
    re(i,m)
    {
        re(j,m)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
    */
    re(j,m)
    {    re(i,m)
        {
            if(a[i])
                continue;
            
            if(vec[i][j]>vec[k][j])
            {
                a[i]=1;
                count++;
                //cout<<i<<" ";
            }
            
            else if(vec[i][j]<vec[k][j])
            {
                a[i]=1;
                //cout<<i<<" ";
            }

        }
    }
   
    re(i,m)
    {
        if((!a[i])&&(i<k))
        {
            count++;
        }       
    }
    
    cout<<count;
    
}