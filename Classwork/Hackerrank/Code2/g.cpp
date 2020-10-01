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
// If anybody is reading
// This question was very easy to find on the internet
// Next time try harder
int isSquare(int n) 
{ 
    int k = sqrt(n); 
    return (k * k == n); 
} 
int calculate(int pos, int prev, 
              int sum, vector<int>& v) 
{ 
  
    if (pos == v.size()) 
        return isSquare(sum); 
  
    // place digits greater than equal to prev 
    for (int i = prev; i <= 9; i++) { 
        v[pos] = i; 
        sum += i * i; 
  
        // check if palcing this digit leads 
        // to a solution then return it 
        if (calculate(pos + 1, i, sum, v)) 
            return 1; 
  
        // else backtrack 
        sum -= i * i; 
    } 
    return 0; 
} 
  
string minValue(int n) 
{ 
  
    vector<int> v(n); 
    if (calculate(0, 1, 0, v)) { 
  
        // create a string representing 
        // the N digit number 
        string answer = ""; 
        for (int i = 0; i < v.size(); i++) 
  
            answer += char(v[i] + '0'); 
  
        return answer; 
    } 
  
    else
        return "-1"; 
} 
int main()
{
    FIO;
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;
        cout<<minValue(n)<<endl;
    }
    
}