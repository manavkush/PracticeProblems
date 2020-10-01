#include<iostream>
#include<string.h>
#include<stdio.h>
#include<bits/stdc++.h>

long long int  countOnes (long long int n)
{
    long long int count=0;
    while (n!=0)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

using namespace std;
int main()
{
    long long int t,n,q,eve,i,cp,cn,j;
    long long int m,p;
    scanf("%lld",&t);
    while(t)
    {
        //----------------------Input----------------------------------------------------

        scanf("%lld %lld",&n , &q);
        long long int a[n],p[q];
        for(i=0;i<n;i++)
            scanf(" %lld",&a[i]);
        for(i=0;i<q;i++)
            scanf(" %lld",&p[i]);
//-----------------------------------------------------------------------------------------------
        for(j=0;j<q;j++)
        {
            eve=0;

        cp=countOnes(p[j]);

        //-----------------------------
        for(i=0;i<n;i++)
        {
            //string binary1 = bitset<32>(a[i]).to_string();
           // m=p^a[i];
            //num=m.count();
            cn=countOnes(a[i]);

            if(cp%2==0&&cn%2==0)
                eve++;
            else if(cp%2!=0&&cn%2!=0)
                eve++;

          //  cout<<m<<endl;
          //  num=0;
           // while(m!=0)
           // {
            //    if(m%10==1)
             //       num++;
               // m=m/10;
            //}

          //  if(num%2==0)
              //  eve++;
           // else    odd++;

        }
        printf("%lld %lld",eve,n-eve);


        printf("\n");
        }
    t--;
    }
}
