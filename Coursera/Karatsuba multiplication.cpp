#include<iostream>
#include<math.h>

using namespace std;

long long int multiply(long long int a,long long int b,int n1)
{
        if(n1>1)
{
        int n2=n1;
        long long int  a1=a/(pow(10,n1/2)) ;
        long long int  b1=a-a1*pow(10,n1/2);

         long long int  c1=b/(pow(10,n1/2));
         long long int d1=b-c1*pow(10,n1/2);

        n1=n1/2;
         long long int z1=multiply(a1,c1,n1);
         long long int z2=multiply(b1,d1,n1);
         long long int z3=multiply(a1+b1,c1+d1,n1);


         return  z1*pow(10,n2)  + z2 + (z3-z1-z2)*pow(10,n2/2);
}
    else    return a*b;
}

int main()
{
     long long int a;
     long long int b;

    cin>>a;
    cin>>b;
    cout<<multiply(a,b,64);

}
