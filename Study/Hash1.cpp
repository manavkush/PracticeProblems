#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	set<int>s;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	long long int sum=int(pow(2,s.size()))-1;
	cout<<sum;
	s.clear();
}
