#include <iostream>
using namespace std;

int main()
{
    int n = 3;

    // Allocate memory for 3 integers
    int *values = new int[n];

    // Read three integers
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    // Display all three integers
    for (int i = 0; i < n; i++)
    {
        cout << values[i] << " ";
    }

    cout << endl;

    // Release the allocated memory
    delete[] values;

    // Reset the pointer
    values = nullptr;

    return 0;
}