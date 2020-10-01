#include<iostream>

using namespace std;
int main()
{   int i=1,prev=1,num=2,temp,sum=0;
    while (num<4000000)
    {
        if (i%3==1)
        {
            sum=sum+num;
        }
        temp=prev;
        prev=num;
        num=num+temp;
        i++;
    }

    cout<<sum;

}
