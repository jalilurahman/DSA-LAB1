#include <iostream>
using namespace std;

void swap(int *pa, int *pb)
{
    // Store value temporarily
    int temp = *pa;

    // Swap the values
    *pa = *pb;
    *pb = temp;
}

int main()
{
    int a = 5, b = 10;

    // Pass the addresses of a and b
    swap(&a, &b);

    cout << a << endl;
    cout << b << endl;

    return 0;
}