#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int *ptr;
    int num = 10;
    ptr = (int *)num;
    ptr++;
    num = (int)ptr;
    printf("%d\n", num);
    return 0;
}