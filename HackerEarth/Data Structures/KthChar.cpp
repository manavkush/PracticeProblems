// This is an excellent example of using hash table
// We created a 2d array with 26 columns and n rows which store the number of occcurances of a letter till
// that index in the string
// We then subtract and check for the k the smallest of them

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

int main()
{
    FASTIO;
    int n,q;
	string str;
	cin>>n>>q;
	cin>>str;
    int hash[n+1][26]={0};
    re(i,26)
    {
        int count=0;
        re1(j,1,n)
        {
            if( str[j-1] == i+'a')
            {
                count++;
                hash[j][i]=count;
            }
            else hash[j][i]=count;
        }
    }
    
    
    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        char ch;
        int sum=0;
        re(i,26)
        {
            if(sum>=k)
                break;
            if(hash[r][i]-hash[l-1][i])
            {
                ch='a'+i;
                sum+=hash[r][i]-hash[l-1][i];
            }

        }
        cout<<ch<<endl;

    }
    

}