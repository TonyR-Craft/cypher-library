#include <string.h>
#include <iostream>

using namespace std;

string Rot13Encrypt(string &input)
{
    if (input == "")
        return input;

    string result;
    for (char c : input)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            result += static_cast<char>((c - base + 13) % 26 + base);
        }
        else
        {
            result += c; // Non-alphabetic characters remain unchanged
        }
    }
    return result;
};

string Rot13Decrypt(string &input)
{
    if (input == "")
        return input;

    string result;
    for (char c : input)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            result += static_cast<char>((c - base + 13) % 26 + base);
        }
        else
        {
            result += c; // Non-alphabetic characters remain unchanged
        }
    }
    return result;
};

bool Rot13Test(string input, string cypher)
{
    string encoded = Rot13Encrypt(input);
    cout << "Original: " << input << endl;
    cout << "Encoded: " << encoded << endl;

    if (encoded != cypher)
        return false;

    // string encoded = "Uryyb, Jbeyq!";
    string decoded = Rot13Decrypt(cypher);
    cout << "Encoded: " << encoded << endl;
    cout << "Decoded: " << decoded << endl;

    if (decoded != input)
        return false;

    return true;
}