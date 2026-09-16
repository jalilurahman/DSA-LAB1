#include <iostream>
using namespace std;

void swap(int **ppa, int **ppb)
{
    // Store value temporarily
    int temp = **ppa;

    // Swap the values using double pointers
    **ppa = **ppb;
    **ppb = temp;
}

int main()
{
    int a = 5, b = 10;

    int *pa = &a;
    int *pb = &b;

    // Pointer-to-pointer variables
    int **ppa = &pa;
    int **ppb = &pb;

    // Swap using pointer-to-pointer
    swap(ppa, ppb);

    cout << a << endl;
    cout << b << endl;

    return 0;
}