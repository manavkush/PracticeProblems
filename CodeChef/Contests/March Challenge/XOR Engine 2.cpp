#include<iostream>
#include<string.h>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    long int t,n,q,eve,odd,i,cp,cn;
    long long int m,p;
    scanf("%d",&t);
    while(t)
    {
        //----------------------Input
        eve=0;odd=0;
        scanf("%d %d",&n , &q);

        long int a[n],p[q];

        for(i=0;i<n;i++)
            scanf(" %d",&a[i]);
        for(i=0;i<q;i++)
            scanf("%d",&p[i]);

       // cp=countOnes(p);

        //-----------------------------
        for(j=0;j<q;j++)
        {
            for(i=0;i<n;i++)
        {

            cn=countOnes(a[i]);

            if(cp%2==0&&cn%2==0)
                eve++;
            else if(cp%2!=0&&cn%2!=0)
                eve++;
            else    odd++;

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
        printf("%d %d",eve,odd);

        t--;
        if(t)    printf("\n");
    }
}
