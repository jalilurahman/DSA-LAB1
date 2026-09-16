#include <iostream>
using namespace std;

int main()
{
    int n;

    // Read and validate n
    do
    {
        cout << "Enter number of marks (1-10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    // Allocate original block
    int *marks = new int[n];

    // Read original marks
    cout << "Enter marks: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(marks + i);
    }

    // Allocate new block with one extra space
    int *newMarks = new int[n + 1];

    // Copy original marks using pointer notation
    for (int i = 0; i < n; i++)
    {
        *(newMarks + i) = *(marks + i);
    }

    // Read the new mark
    cout << "Enter new mark: ";
    cin >> *(newMarks + n);

    // Release old block
    delete[] marks;

    // Make marks point to the new block
    marks = newMarks;

    // Update size
    n++;

    // Display all marks
    cout << "Marks: ";
    for (int i = 0; i < n; i++)
    {
        cout << *(marks + i) << " ";
    }

    cout << endl;

    // Release final block exactly once
    delete[] marks;
    marks = nullptr;

    return 0;
}