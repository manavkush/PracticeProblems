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
    unordered_map<lli,lli> ma;
    unordered_map<lli,lli> tot;
    multiset<lli> s;
    while(t--)
    {
        int n;
        cin>>n;
        re(i,n) {   
            cin>>a[i];
            ma[a[i]]++;
            tot[a[i]]++;
        }
        re(i,n) {
            cin>>b[i];
            tot[b[i]]++;
        }
        int flag=0;
        // for(auto it=tot.begin();it!=tot.end();it++)
        // {
        //     cout<<it->first<<": "<<it->second;
        //     cout<<endl;
        // }
        

                            //Checking if the freq of all numbers is even
        //===============================================================
        lli count=0;
        for(auto it=tot.begin();it!=tot.end();it++)
        {
            if((it->second)%2)  {
                flag=1;
                break; 
            }
            lli num=(it->second)/2;
            auto temp=ma.find(it->first);
            if(temp==ma.end())
            {
                count+=num;
            }
            else
            {
                count+=abs(num-temp->second);
            }
        }

        if(flag)        //Condition when freq. of a number is odd
        {
            cout<<-1<<endl;
            ma.clear();
            if(!s.empty())
                s.clear();
            tot.clear();
            continue;
        }
        
        count=count/2;
        //==============================================================

        //==============================================================
        for(auto it=tot.begin();it!=tot.end();it++)
        {
            lli num=(it->second)/2;
            auto temp=ma.find(it->first);
            //If the map-a does not have that element
            if(temp==ma.end())
            {
                re(i,num)
                    s.insert(it->first);
            }
             //If the map-a has that element
            else 
            {
                    re(i,abs(num-(temp->second)))
                    s.insert(it->first);
            }
        }
        lli sum=0;
        lli k=0;
        for(auto itr=s.begin();itr!=s.end()&&(k<count);itr++)
        {
            k++;
            sum+=(*itr);
        }

        // for(auto it=s.begin();it!=s.end();it++)
        // {
        //     cout<<*it<<" ";
        // }
        //cout<<endl;
        cout<<sum<<endl;
        if(!s.empty())
            s.clear();
        tot.clear();
        ma.clear();

    }
}