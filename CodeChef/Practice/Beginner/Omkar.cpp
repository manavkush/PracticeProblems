#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

long long int j;
long long int k;
long long int count=0;
long long int allints[100001];
long long int queryints;
long long int result=0;
long long int N,Q,even,odd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     long long int T;
    cin>>T;

    while(T--)
    {
        cin>>N;
        cin>>Q;
        even=0;
        odd=0;

        for(j=0;j<N;j++)
        {
         count=0;
         cin>>allints[j];
        while(allints[j])
         {
        allints[j]=allints[j]&allints[j]-1;
        count++;

          }
        allints[j]=count;
        if (count%2==0)
            even++;
        else odd++;
        }
       // scanf("\n");

        for(j=0;j<Q;j++)
        {
         count =0;
        cin>>queryints;
        while(queryints)
        {
            queryints=queryints&queryints-1;
            count++;
        }
      //  queryints=count;

        if(count%2==0)
            cout<<even<<" "<<odd<<"\n";
        else    cout<<odd<<" "<<even<<"\n";
 //---------------------------------------------------------------------
        //result=0;
       // for(k=0;k<N;k++)
       // {
         //    if(queryints%2==0 && allints[k]%2==0)
       //  result+=0;
    //else if(queryints%2==1 && allints[k]%2==0)
       //  result+=1;
    //else if(queryints%2==0 && allints[k]%2==1)
       //  result+=1;
    //else
      //   result+=0;

        }
   // cout<<N-result<<" "<<result<<"\n";
    }


}

