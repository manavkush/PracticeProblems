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

string decimalToBinary(int n) 
{ 

    string ans; 

    int i = 0; 
    while (n > 0) { 

         if(n % 2)
            ans += '1';
         else ans+='0';
         
        n = n / 2; 
        i++; 
    } 
    reverse(ans.begin(),ans.end());

    return ans; 
}
int main()
{
    FIO;
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        re(i,n)
        {
            cin>>a[i];
        }
        int e1=(*max_element(a.begin(),a.end()));
        int e2=(*min_element(a.begin(),a.end()));
        string str1 = decimalToBinary(e1);
        string str2 = decimalToBinary(e2);
            // str1.erase(0, min(str1.find_first_not_of('0'), str1.size()-1));
            // str2.erase(0, min(str2.find_first_not_of('0'), str2.size()-1));
        cout<<max(solve(str1,str2),solve(str2,str1))<<endl;
    }
}