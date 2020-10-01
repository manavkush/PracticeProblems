#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vlli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FASTIO;
    int t,n;
    cin>>t;
    vi vec;
    int temp,prev,count,i;
    while(t--)
    {
        cin>>n;
        count=0;
        re(i,n)
        {
            cin>>temp;
            if(i==0)
            {   prev=temp;      count++;    }
            else if(temp-prev<=2)    {
                    count++;
                    prev=temp;
                }
           else        {
                    vec.push_back(count);
                    count=1;
                    prev=temp;
                }
        }
        vec.push_back(count);

        sort(vec.begin(),vec.end());
        cout<<vec[0]<<" "<<vec[vec.size()-1]<<endl;
        vec.clear();
    }

}
