#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int bit;
    Node* next;
    Node* prev;
};

class BinaryNumber
{
private:
    Node* head;
    Node* tail;

public:
    BinaryNumber()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Store Binary Number
    void insertBit(int bit)
    {
        Node* newNode = new Node;

        newNode->bit = bit;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Create binary number from string
    void create(string binary)
    {
        for (char c : binary)
        {
            if (c == '0' || c == '1')
            {
                insertBit(c - '0');
            }
        }
    }

    // Display binary number
    void display()
    {
        Node* current = head;

        while (current != nullptr)
        {
            cout << current->bit;
            current = current->next;
        }

        cout << endl;
    }

    // 1's Complement
    void onesComplement()
    {
        Node* current = head;

        while (current != nullptr)
        {
            current->bit = 1 - current->bit;
            current = current->next;
        }
    }

    // Add 1 to binary number
    void addOne()
    {
        Node* current = tail;
        int carry = 1;

        while (current != nullptr && carry == 1)
        {
            if (current->bit == 0)
            {
                current->bit = 1;
                carry = 0;
            }
            else
            {
                current->bit = 0;
                carry = 1;
            }

            current = current->prev;
        }

        if (carry == 1)
        {
            Node* newNode = new Node;

            newNode->bit = 1;
            newNode->prev = nullptr;
            newNode->next = head;

            head->prev = newNode;
            head = newNode;
        }
    }

    // 2's Complement
    void twosComplement()
    {
        onesComplement();
        addOne();
    }

    // Convert DLL to string
    string toString()
    {
        string result = "";

        Node* current = head;

        while (current != nullptr)
        {
            result += char(current->bit + '0');
            current = current->next;
        }

        return result;
    }

    // Binary Addition
    static BinaryNumber add(BinaryNumber& a, BinaryNumber& b)
    {
        BinaryNumber result;

        Node* p = a.tail;
        Node* q = b.tail;

        int carry = 0;

        while (p != nullptr || q != nullptr || carry != 0)
        {
            int bitA = 0;
            int bitB = 0;

            if (p != nullptr)
            {
                bitA = p->bit;
                p = p->prev;
            }

            if (q != nullptr)
            {
                bitB = q->bit;
                q = q->prev;
            }

            int sum = bitA + bitB + carry;

            int resultBit = sum % 2;
            carry = sum / 2;

            // Insert at beginning
            Node* newNode = new Node;

            newNode->bit = resultBit;
            newNode->prev = nullptr;
            newNode->next = result.head;

            if (result.head != nullptr)
            {
                result.head->prev = newNode;
            }
            else
            {
                result.tail = newNode;
            }

            result.head = newNode;
        }

        return result;
    }

    // Binary Multiplication
    static BinaryNumber multiply(BinaryNumber& a, BinaryNumber& b)
    {
        BinaryNumber result;
        result.insertBit(0);

        Node* multiplier = b.tail;
        int shift = 0;

        while (multiplier != nullptr)
        {
            if (multiplier->bit == 1)
            {
                BinaryNumber partial;

                Node* current = a.head;

                while (current != nullptr)
                {
                    partial.insertBit(current->bit);
                    current = current->next;
                }

                // Add zeros for shifting
                for (int i = 0; i < shift; i++)
                {
                    partial.insertBit(0);
                }

                BinaryNumber temp = add(result, partial);

                result = temp;
            }

            shift++;
            multiplier = multiplier->prev;
        }

        return result;
    }

    // Binary to Decimal
    long long toDecimal()
    {
        long long decimal = 0;

        Node* current = head;

        while (current != nullptr)
        {
            decimal = decimal * 2 + current->bit;
            current = current->next;
        }

        return decimal;
    }
};

int main()
{
    int choice;

    do
    {
        cout << "\n===== BINARY ARITHMETIC USING DOUBLY LINKED LIST =====\n";
        cout << "1. Store and Display Binary Number\n";
        cout << "2. 1's Complement\n";
        cout << "3. 2's Complement\n";
        cout << "4. Binary Addition\n";
        cout << "5. Binary Multiplication\n";
        cout << "6. Binary to Decimal\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string binary;

            cout << "Enter binary number: ";
            cin >> binary;

            BinaryNumber number;
            number.create(binary);

            cout << "Stored Binary: ";
            number.display();
        }

        else if (choice == 2)
        {
            string binary;

            cout << "Enter binary number: ";
            cin >> binary;

            BinaryNumber number;
            number.create(binary);

            number.onesComplement();

            cout << "1's Complement: ";
            number.display();
        }

        else if (choice == 3)
        {
            string binary;

            cout << "Enter binary number: ";
            cin >> binary;

            BinaryNumber number;
            number.create(binary);

            number.twosComplement();

            cout << "2's Complement: ";
            number.display();
        }

        else if (choice == 4)
        {
            string binary1;
            string binary2;

            cout << "Enter first binary number: ";
            cin >> binary1;

            cout << "Enter second binary number: ";
            cin >> binary2;

            BinaryNumber number1;
            BinaryNumber number2;

            number1.create(binary1);
            number2.create(binary2);

            BinaryNumber result =
                BinaryNumber::add(number1, number2);

            cout << "Binary Sum: ";
            result.display();
        }

        else if (choice == 5)
        {
            string binary1;
            string binary2;

            cout << "Enter first binary number: ";
            cin >> binary1;

            cout << "Enter second binary number: ";
            cin >> binary2;

            BinaryNumber number1;
            BinaryNumber number2;

            number1.create(binary1);
            number2.create(binary2);

            BinaryNumber result =
                BinaryNumber::multiply(number1, number2);

            cout << "Binary Product: ";
            result.display();
        }

        else if (choice == 6)
        {
            string binary;

            cout << "Enter binary number: ";
            cin >> binary;

            BinaryNumber number;
            number.create(binary);

            cout << "Decimal: "
                 << number.toDecimal() << endl;
        }

        else if (choice == 7)
        {
            cout << "Exiting program...\n";
        }

        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
