//     SHINZOU WO SASAGEYO

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
const int N=2e5+10;
lli a[N];
lli b[N];
int main()
{
    FIO;
    int t;
    cin>>t;
    
    while(t--)
    {
        map<lli,lli> ma;
        map<lli,lli> mb;
        map<lli,lli> tot;
        multiset<lli> sa;
        multiset<lli> sb;
        int n;
        cin>>n;
        int a[n];
        int b[n];
        re(i,n) {   
            cin>>a[i];
            ma[a[i]]++;
            tot[a[i]]++;
        }
        re(i,n) {
            cin>>b[i];
            mb[b[i]]++;
            tot[b[i]]++;
        }
        int flag=0;
                      //Checking if the freq of all numbers is even
        //===============================================================
        for(auto it=tot.begin();it!=tot.end();it++)
        {
            if((it->second)%2)  {
                flag=1;
                break; 
            }
        }
        if(flag)        //Condition when freq. of a number is odd
        {
            cout<<-1<<endl;
            ma.clear();
            mb.clear();
            tot.clear();
            sa.clear();
            sb.clear();
            continue;
        }//==========================MAKING 2 MULTISETS FOR EXCESS ELEMENTS IN THE 2 ARRAYS===============
        lli sum=0;
        for(auto it=ma.begin();it!=ma.end();it++)
        {
            lli el=it->first;
            if(it->second>tot[el]/2)
            {
                re(i,it->second-(tot[el]/2))
                    sa.insert(it->first);
            }   
        }
        for(auto it=mb.begin();it!=mb.end();it++)
        {
            lli el=it->first;
            if(it->second>tot[el]/2)
            {
                re(i,it->second-(tot[el]/2))
                    sb.insert(it->first);
            }   
        }
        //=======================================
        // tr(it,sa)   cout<<*it<<" ";
        // cout<<endl;
        // tr(it,sb)   cout<<*it<<" ";
        // cout<<endl;
        //=======================================
        while((!sa.empty())&&(!sb.empty()))
        {
            if((*sa.begin())<(*sb.begin()))
            {
                sum+=*sa.begin();
                sa.erase(sa.begin());
                sb.erase(prev(sb.end()));
            }
            else
            {
                sum+=*sb.begin();
                sb.erase(sb.begin());
                sa.erase(prev(sa.end()));
            }
            
        }
        cout<<sum<<endl;

        ma.clear();
        mb.clear();
        tot.clear();

    }
}