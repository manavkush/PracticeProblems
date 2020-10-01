#include<iostream>

using namespace std;
int main()
{
    char *String ;
    char arr[20]={'a',',g','r','e','r'};
    String=arr;
    int *Ptr, A[]={1,5,7,9};
    Ptr=A;
    cout<<*Ptr<<String<<endl;
    String++;
    Ptr+=3;
    cout<<*Ptr<<String<<endl;
}
