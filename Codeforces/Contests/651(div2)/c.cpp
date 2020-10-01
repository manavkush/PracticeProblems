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
bool isPowerOfTwo (int x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
} 
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
int main()
{
    FIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string str1,str2;
        str1="Ashishgup";
        str2="FastestFinger";
        cin>>n;
        if(n==1)
        {
            cout<<str2<<endl;       
        }
        else if(n==2)
        {
            cout<<str1<<endl;
        }
        else if(n%2)
        {
            cout<<str1<<endl;       // if odd ashish wins on first move
        }
        else    // if even
        {
            if(isPowerOfTwo(n))         //if power of 2 then no odd divisors, so he has to subtract 1. fastesst wins
            {
                cout<<str2<<endl;
            }
            else
            {
                if(n%4==0)              // if power of 
                {
                    cout<<str1<<endl;
                }
                else if(isPrime(n/2))
                {
                    cout<<str2<<endl;
                }
                else
                {
                    cout<<str1<<endl;
                }
                               
            }
            
        }


    }
}