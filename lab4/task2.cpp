#include <iostream>
using namespace std;

struct Person
{
    int id;
    Person* next;
};

class CircularLinkedList
{
private:
    Person* last;

public:
    CircularLinkedList()
    {
        last = nullptr;
    }

    // Add a person to the circular linked list
    void addPerson(int id)
    {
        Person* newPerson = new Person;
        newPerson->id = id;

        if (last == nullptr)
        {
            last = newPerson;
            newPerson->next = last;
        }
        else
        {
            newPerson->next = last->next;
            last->next = newPerson;
            last = newPerson;
        }
    }

    // Display the circular linked list
    void display()
    {
        if (last == nullptr)
        {
            cout << "Circle is empty." << endl;
            return;
        }

        Person* current = last->next;

        cout << "People in the circle: ";

        do
        {
            cout << current->id << " ";
            current = current->next;
        }
        while (current != last->next);

        cout << endl;
    }

    // Josephus Problem
    void josephus(int k)
    {
        if (last == nullptr || k <= 0)
        {
            cout << "Invalid input." << endl;
            return;
        }

        Person* current = last->next;
        Person* previous = last;

        cout << "\nElimination order: ";

        while (current->next != current)
        {
            // Move k-1 steps
            for (int count = 1; count < k; count++)
            {
                previous = current;
                current = current->next;
            }

            cout << current->id << " ";

            // Remove current person
            previous->next = current->next;

            if (current == last)
            {
                last = previous;
            }

            delete current;

            current = previous->next;
        }

        cout << "\nSurvivor: " << current->id << endl;

        delete current;
        last = nullptr;
    }
};

int main()
{
    CircularLinkedList circle;

    int n;
    int k;

    cout << "===== JOSEPHUS PROBLEM =====" << endl;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter counting number (k): ";
    cin >> k;

    if (n <= 0 || k <= 0)
    {
        cout << "Invalid input." << endl;
        return 0;
    }

    // Create circular linked list
    for (int i = 1; i <= n; i++)
    {
        circle.addPerson(i);
    }

    circle.display();

    circle.josephus(k);

    return 0;
}
