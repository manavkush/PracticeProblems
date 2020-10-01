#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define REP(i,n)        for(int i=0;i<(n);i++)
#define FOR(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    vector <lli> vec1,vec2;
    lli i,n,temp,dif,j;
    int flag;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        vec1.push_back(temp);
    }
    for(i=0;i<n;i++)
    {
        cin>>temp;
        vec2.push_back(temp);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());

    i=j=n-1;
    //sum1=sum2=
    dif=0;
    flag=0;
    //================================================
    while(i>=0&&j>=0)
    {
        if(flag==0)       // When it's p1's chance

       {
            if(vec1[i]>vec2[j])
            {
                dif+=vec1[i];
                i--;
            }
            else
                j--;
            flag=1;
        }

         else        // When it's p2's chance
        {
            if(vec2[j]>vec1[i])
            {
                dif-=vec2[j];
                j--;
            }
            else
                i--;
            flag=0;
        }
    }
    //============================================

    if(i<0)
    {
        if(flag==0)
            j--;

            while(j>=0)
            {
                dif-=vec2[j];
                j=j-2;
            }
    }

    //================================================
    else if(j<0)
    {
        if(flag==1)
            i--;
        while(i>=0)
        {
            dif+=vec1[i];
            i=i-2;
        }
    }
    cout<<dif;

}
