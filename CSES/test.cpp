#include <bits/stdc++.h>
using namespace std;

// #define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define re(i,n)        for(int i=0;i<(n);i++)

const int mod = 1000000007;
long long dp[10000002][2];

int main()
{
    FIO;
    const int N = 1e6+1;
    
    // vector<vector<int>> dp(2, vector<int> (N, -1));
    
    dp[1][1] = 1;
    dp[1][0] = 1;

    for(int i=2;i<=1000002;i++) {
        dp[i][1] = (4*dp[i-1][1]+dp[i-1][0])%mod;
        dp[i][0] = (2*dp[i-1][0]+dp[i-1][1])%mod;
    }
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<(dp[n][1]+dp[n][0])%mod<<endl;
    }
}