#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int t;
      long long int x,k,i,cnt;
      cin>>t;
      while(t--)
      {     cin>>x>>k;
            cnt=0;

    // Print the number of 2s that divide n
    while (x % 2 == 0)
    {
        cnt++;
        x = x/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for ( i = 3; i <= sqrt(x); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (x % i == 0)
        {
            cnt++;
            x = x/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (x > 2)
        cnt++ ;




      if(cnt>=k)
            cout<<"1\n";
      else  cout<<"0\n";

      }

}
