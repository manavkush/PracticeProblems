#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n,r;
    cin>>n>>r;
    cout<<fixed;
    double R=r*(sin(2*acos(0.0)/n))/(1-sin(2*acos(0.0)/n));
    cout<<setprecision(8)<<R;
}