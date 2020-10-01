#include <iostream>
#include<vector>

using namespace std;
int main()
{
    int temp,i,j;
    int scoreA,scoreB;
    vector <int> secA,secB;

    //Entering score and time of A
    cin>>scoreA;
    for(i =0;i<scoreA;i++)
    {

        cin>>temp;
        secA.push_back(temp);
    }
    //Entering score and time of B
    cin>>scoreB;
    for( i =0;i<scoreB;i++)
    {
        cin>>temp;
        secB.push_back(temp);
    }

    // Points in first half
    i=0;
    temp=0;
    while(secA[i]<=1440&&i<scoreA)
    {
        temp++;
        i++;
    }

    i=0;                //reset for second player
    while(secB[i]<=1440&&i<scoreB)
    {
        temp++;
        i++;
    }
    cout<<endl<<temp;

    // counters for 2 loops
    i=1; j=1; temp=0;
    int low=min(scoreA,scoreB);


    //          secA[i]<scoreA||secB[j]<scoreB
    //------------------------------------------------------

while(i<low)
{
    if( secA[i-1]>secB[i-1] && secA[i]<secB[i])
    {
        temp++;
    }
    else if( secA[i-1]<secB[i-1] && secA[i]>secB[i])
    {
        temp++;
    }
    i++;
}

if(scoreA<scoreB)
{
    if (secA[i-1]<secB[i-1])
    temp++;
}
else if(scoreA<scoreB)
{
    if (secA[i-1]>secB[i-1])
    temp++;
}

cout<<endl<<temp;

}
