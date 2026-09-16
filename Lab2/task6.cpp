#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    // Read and validate rows and columns
    do
    {
        cout << "Enter number of students: ";
        cin >> rows;
    } while (rows <= 0);

    do
    {
        cout << "Enter number of subjects: ";
        cin >> cols;
    } while (cols <= 0);

    // Allocate row pointers
    int **marks = new int*[rows];

    // Allocate columns for each row
    for (int r = 0; r < rows; r++)
    {
        marks[r] = new int[cols];
    }

    // Input marks
    for (int r = 0; r < rows; r++)
    {
        cout << "Enter marks for student " << r + 1 << ": ";

        for (int c = 0; c < cols; c++)
        {
            cin >> *(*(marks + r) + c);
        }
    }

    // Display the matrix
    cout << "\nMarks Matrix:\n";

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cout << *(*(marks + r) + c) << " ";
        }

        cout << endl;
    }

    // Calculate totals
    int bestTotal = 0;
    int bestStudent = 1;

    for (int c = 0; c < cols; c++)
    {
        bestTotal += *(*(marks + 0) + c);
    }

    for (int r = 1; r < rows; r++)
    {
        int total = 0;

        for (int c = 0; c < cols; c++)
        {
            total += *(*(marks + r) + c);
        }

        if (total > bestTotal)
        {
            bestTotal = total;
            bestStudent = r + 1;
        }
    }

    // Display highest total
    cout << "\nTop student: " << bestStudent << endl;
    cout << "Highest total: " << bestTotal << endl;

    // Delete each row
    for (int r = 0; r < rows; r++)
    {
        delete[] marks[r];
    }

    // Delete row-pointer array
    delete[] marks;

    // Set pointer to nullptr
    marks = nullptr;

    return 0;
}