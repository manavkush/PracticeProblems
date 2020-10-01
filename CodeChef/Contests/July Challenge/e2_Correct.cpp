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
        unordered_map<lli,lli> ma;
        unordered_map<lli,lli> mb;
        unordered_map<lli,lli> tot;
        multiset<lli> sa;
        multiset<lli> sb;
        int n;
        cin>>n;
        int a[n];
        int b[n];
        lli mn=1e9;
        re(i,n) {   
            cin>>a[i];
            if(a[i]<mn)
                mn=a[i];
            ma[a[i]]++;
            tot[a[i]]++;
        }
        re(i,n) {
            cin>>b[i];
            if(b[i]<mn)
                mn=b[i];
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
        }
        //==========================MAKING 2 MULTISETS FOR EXCESS ELEMENTS IN THE 2 ARRAYS===============
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
        if(sa.empty())
        {
            cout<<0<<endl;
            ma.clear();
            mb.clear();
            tot.clear();
            continue;
        }
        // int cse=0;
        // auto temp=ma.find(mn);
        // if(temp==ma.end())
        //     cse=1;
        // else
        // {
        //     if(temp->second<tot[mn]/2)
        //         cse =1;
        //     else if(temp->second>tot[mn]/2)
        //         cse = 2;
        // }
        //=============================
        // while(!sa.empty())
        // {
        //     if(cse==1)
        //     {
        //         while((*sb.begin())==mn&&(!sa.empty()))
        //         {
        //             sum+=mn;
        //             sb.erase(sb.begin());
        //             sa.erase(prev(sa.end()));
        //         }
        //     }
        //     else if(cse==2)
        //     {
        //         while((*sa.begin())==mn&&(!sa.empty()))
        //         {
        //             sum+=mn;
        //             sa.erase(sa.begin());
        //             sb.erase(prev(sb.end()));
        //         }
        //     }
        // }
        //===========================================
        while((!sa.empty())&&(!sb.empty()))
        {
            int num1=(*sa.begin());
            int num2=(*sb.begin());
            if(mn*2<(min(num1,num2)))
            {
                sum+=2*mn;
                /// I have left here. I need to redo this. Till now I have balanced the mnimum element.
                // Now I just want to see how many times do we need the mn element swapping instead of direct swapping
                // if(num1<num2)
                // {
                sa.erase(sa.begin());
                sb.erase(prev(sb.end()));
                // }
                // else
                // {
                // sb.erase(sb.begin());
                // sa.erase(prev(sa.end()));
                // }
            }
            else if(num1<num2)
            {
                sum+=num1;
                sa.erase(sa.begin());
                sb.erase(prev(sb.end()));
            }
            else
            {
                sum+=num2;
                sb.erase(sb.begin());
                sa.erase(prev(sa.end()));
            }
            
        }
        //==============================================
        cout<<sum<<endl;
        ma.clear();
        mb.clear();
        sa.clear();
        sb.clear();
        tot.clear();

    }
}