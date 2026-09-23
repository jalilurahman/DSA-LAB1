#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertAtHead(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtThird(Node*& head, int value)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "List has fewer than 2 nodes." << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = head->next->next;
    head->next->next = newNode;
}

void displayList(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

void deleteLast(Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;

    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

int countNodes(Node* head)
{
    int count = 0;
    Node* current = head;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}

void reverseList(Node*& head)
{
    Node* previous = nullptr;
    Node* current = head;
    Node* nextNode;

    while (current != nullptr)
    {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
}

void searchValue(Node* head, int value)
{
    Node* current = head;
    int position = 1;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            cout << "Value found at position " << position << endl;
            return;
        }

        current = current->next;
        position++;
    }

    cout << "Value not found." << endl;
}

void destroyList(Node*& head)
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node* head = nullptr;
    int choice, value;

    do
    {
        cout << "\n--- Linked List Menu ---" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at 3rd Position" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Delete Last Node" << endl;
        cout << "5. Count Nodes" << endl;
        cout << "6. Reverse List" << endl;
        cout << "7. Search Value" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtThird(head, value);
            break;

        case 3:
            displayList(head);
            break;

        case 4:
            deleteLast(head);
            displayList(head);
            break;

        case 5:
            cout << "Number of nodes: " << countNodes(head) << endl;
            break;

        case 6:
            reverseList(head);
            displayList(head);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            searchValue(head, value);
            break;

        case 8:
            destroyList(head);
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 8);

    return 0;
}
