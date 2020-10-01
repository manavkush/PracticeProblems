#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t,n,i,j,flag;
    long long int m,temp;
    vector <long long int> arr;
    cin>>t;
    while(t)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end());

        flag=0;
        int low = 0;
        int high = n - 1;
	while (low < high)
	{

		if (arr[low] + arr[high] == m)
		{
			flag=1;
			break;
		}
		if(arr[low] + arr[high] < m)
             low++;
        else
            high--;
	}
        if(flag==1)
            cout<<"YES\n";
        else    cout<<"NO\n";

        t--;
        arr.clear();
    }
}
