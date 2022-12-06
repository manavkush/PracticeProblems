#include<bits/stdc++.h>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {real = r;   imag = i;}
     
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator ^(int a) {
         Complex res;
         res.real = (__builtin_popcount(real));
         res.imag = (__builtin_popcount(imag));
         return res;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
};
 
int main()
{
    Complex c1(15, 7), c2(2, 4);
    Complex c3 = c1^1;
    c3.print();
}