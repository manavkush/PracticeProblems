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
    int k,n;
    string str;
    cin>>str;
    cin>>k;
    vi num1,num2;
    n=str.size();
    int sz,req,i,j,a=0,b=0;
    re(i,str.size())
    {
        if(str[i]=='*')
        {
            b++;
            num2.push_back(i);
        }
        else if(str[i]=='?')
        {
            a++;
            num1.push_back(i);
        }
    }
    sz=str.size()-a-b;
    //=============================================
    if(sz==k)
    {
        for(i=0;i<str.size();i++)
        {
            if(str[i]!='*'&&str[i]!='?')
                cout<<str[i];
        }
        return 0;
    }
    //=====================================
    else if(k<sz)
    {
        if(k<sz-a-b){
            cout<<"Impossible";
            return 0;
            }
        req=k-sz+a+b;
        int count=0;
        for(i=0;i<n;i++)
        {
            if(str[i]!='*'&&str[i]!='?')
            {
                if(str[i+1]=='*'||str[i+1]=='?')
                    {   if(count<req)
                            count++;
                        else
                            cout<<str[i];
                    }
                else
                        cout<<str[i];
            }
        }
    }
    //=====================================================
    else if(k>sz)
    {
        req=k-sz;
        if(a)
        {
            for(i=0;i<n;i++)
            {
                if(str[i]!='*'&&str[i]!='?')
                        cout<<str[i];
                else if(str[i]=='*')
                {
                    re(j,req)
                        cout<<str[i-1];
                }
            }
        }
        else
        {
            req=sz+b-k;
            if(sz+b<k)
            {
                cout<<"Impossible";
                return 0;
            }
            else
            {
                re(i,n)
                {
                    if(str[i]!='*'&&str[i]!='?')
                                cout<<str[i];
                    else
                    {
                        if(req)
                        {
                            cout<<str[i-1];
                            req--;
                        }
                    }
                }
            }

        }

    }
}
