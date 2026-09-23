#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string str)
{
    string clean = "";

    for (char ch : str)
    {
        if (isalnum(ch))
            clean += tolower(ch);
    }

    int left = 0;
    int right = clean.length() - 1;

    while (left < right)
    {
        if (clean[left] != clean[right])
            return false;

        left++;
        right--;
    }

    return true;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    if (isPalindrome(str))
        cout << "Palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;

    return 0;
}
