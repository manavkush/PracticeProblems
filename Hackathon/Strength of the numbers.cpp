#include<iostream>
#include<vector>
using namespace std;

int strength(int num)                   // Defining a function strength to calculate the strength
{

             vector<int> vec;
             int i,str;
             vec.push_back(num);

              while(num!=2)                         // we check if the number is not 2
                    {
                        for(i=2;i<num;i++)
                            {
                                if(num%i!=0)                // condition to check if i is the smallest non divisor
                                   {
                                    vec.push_back(i);               // enters the element to the vector
                                    num=i;                                  // the smallest non divisor becomes the next element
                                    break;
                                   }
                            }
                    }

                str=vec.size();

       return str;
}
//-------------------------------------------------------   Main Function---------------------------------------------

int main()
{
    int a,b,i,sum=0;
    cin>>a;             // first number
    cin>>b;             // second number


    for(i=a;i<=b;i++)           // calculating the sum of the function
    {
        sum=sum+strength(i);
    }

   cout<<endl<<sum;

}


