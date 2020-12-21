#include <bits/stdc++.h>
using namespace std;
// dp[money][j] = max( (pages[j] + dp[money-cost[j]][j-1] ), dp[money][j-1] )
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> cost(n), pages(n);
    // States--> Money, Books   // Stores the max pages you can buy
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));   
    
    for(int &i : cost) cin>>i;
    for(int &i : pages) cin>>i;
    
    for (int j = 1; j <= n; j++) {  
        //   i-th book choosen or not
        for(int money=0;money<=x;money++) { 
            // iterating over the sum of money. To check for each amount
            
            dp[j][money] = dp[j-1][money];
            int after = money - cost[j-1];

            if (after>=0) {
                dp[j][money] = max(dp[j-1][after] + pages[j-1], dp[j][money] );
            }
        }
    }
    cout<<dp[n][x]<<endl;
}