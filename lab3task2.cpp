#include <iostream>
#include <string>
using namespace std;

class StringPool
{
private:
    string* stringPool;
    int currentSize;
    int maxSize;

public:
    StringPool()
    {
        maxSize = 5;
        currentSize = 0;
        stringPool = new string[maxSize];
    }

    void addString(string str)
    {
        if (currentSize < maxSize)
        {
            stringPool[currentSize] = str;
            currentSize++;
        }
        else
        {
            cout << "Pool is full." << endl;
        }
    }

    void removeString(string str)
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (stringPool[i] == str)
            {
                for (int j = i; j < currentSize - 1; j++)
                {
                    stringPool[j] = stringPool[j + 1];
                }

                currentSize--;
                stringPool[currentSize].clear();
                cout << str << " removed." << endl;
                return;
            }
        }

        cout << str << " not found." << endl;
    }

    void displayPool()
    {
        cout << "\nPool Status:" << endl;

        for (int i = 0; i < currentSize; i++)
        {
            cout << i + 1 << ". " << stringPool[i] << endl;
        }
    }

    ~StringPool()
    {
        delete[] stringPool;
        stringPool = nullptr;
    }
};

int main()
{
    StringPool pool;

    pool.addString("Apple");
    pool.addString("Banana");
    pool.addString("Mango");
    pool.addString("Orange");
    pool.addString("Grapes");

    pool.displayPool();

    pool.removeString("Mango");
    pool.removeString("Orange");

    pool.displayPool();

    return 0;
}
