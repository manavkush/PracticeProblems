#include <iostream>

int main()
{
const int i=90;

if constexpr (i) //'if constexpr' is part of C++17
{ std::cout<< "True!"; }
else
{ std::cout<<"False" ; }

std::cin.get();
return 0;
}
