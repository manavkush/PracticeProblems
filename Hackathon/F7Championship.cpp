#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{

    int i,n,temp,winner=0,j,flag;           // declaring counters(i,j) ; temporary int( temp) ; possible winners ; flag integer
    cin>>n;
    int players[n];
    for(i=0;i<n;i++)
    {
        cin>>players[i];
    }


    sort(players, players + n, greater<int>());         // sorting the array in descending order


    for (int i=0;i<n;i++)
        {
                swap(players[n-i-1],players[n-1]);                       // In this program i am taking elements from bottom and comparing to all above elements
                                                                                                    // as it's the best case scenario  for a racer to win a race. Then we swap the next element so that it comes to
                                                                                                    // the bottom of the vector. Then we again do the comparison for the new element
                flag=0;
                for(j=n-2;j>=0;j--)
                    {

                                if (  (players[n-1]+n)  <  (players[j]+j+1)  )
                                        {
                                                flag=1;                                                     // if the flag=1 means that the racer cannot win the race even in the best case scenario
                                        }

                    }

                    if(flag==0)
                        winner++;               // increasing the value of possible winners

        }


cout<<endl<<winner;


}
