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
float cal(float t,int k,float h,float c)
{
        return abs(t- ((k+1)*h+k*c)/(2*k+1) );
}
int main()
{
        FASTIO;
        int q;
        cin>>q;
        while(q--)
        {
                float h,c,t;

                cin>>h>>c>>t;
                float m=(h+c)/2;
                if(t<=(h+c)/2)
                        cout<<2<<endl;
                else
                {
                       int k=(0.5*(h-c)/(t-m) -1)/2;
                       float diff1=cal(t,k,h,c);
                       float diff2=cal(t,k+1,h,c);
                       float diff3=cal(t,k-1,h,c);
                       float temp=min(diff1,diff2);
                       float mim=min(temp,diff3);
                       if(mim==diff1)   cout<<2*k+1<<endl;
                       else if(mim==diff2)    cout<<2*k+3<<endl;
                       else     cout<<2*k-1<<endl;
                }

        }


}
