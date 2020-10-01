#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int t,i;                    // declaring t(no of cases to test), i (counter)
    cin>>t;
    int arr[2][t];              // 2d array to store n&m pairs i.e. each test case
//-----------------------------------------
    for(i=0;i<t;i++)
    {
        cin>>arr[0][i];                                                 // inputing the test cases
        cin>>arr[1][i];
    }
//===============================
for(i=0;i<t;i++)
   {
       if(arr[1][i] == 1 || arr[0][i] % 2 == 0)                 // condition to check if the height of tower=1 or if the number of towers is even: then 2 wins
                cout << 2 << endl;
       else cout << 1 << endl;
   }

}
