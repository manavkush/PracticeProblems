#include <iostream>

using namespace std;

int main()
{
    int i,n;
    for(i=0;i<10;i++)
    {
        cin>>n;
        while(n<(n/2+n/3+n/4))
        {
            n=(n/2+n/3+n/4);
        }
        cout<<n;

    }
}
