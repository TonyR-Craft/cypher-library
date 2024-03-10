#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// A function to encrypt a message using the rail fence cipher
string RailFenceEncrypt(string input, int key)
{
    // Create a matrix of key rows and message length columns
    int rows = key;
    int cols = input.length();
    char matrix[rows][cols];

    // Initialize the matrix with null characters
    fill(&matrix[0][0], &matrix[0][0] + rows * cols, '\0');

    // Fill the matrix with the message characters in a zigzag pattern
    int row = 0;      // The current row
    int col = 0;      // The current column
    bool down = true; // The direction of movement
    for (int i = 0; i < cols; i++)
    {
        // Place the current character in the matrix
        matrix[row][col] = input[i];
        col++;

        // Change the direction if we reach the top or bottom rail
        if (row == 0)
        {
            down = true;
        }
        if (row == rows - 1)
        {
            down = false;
        }

        // Move to the next row according to the direction
        if (down)
        {
            row++;
        }
        else
        {
            row--;
        }
    }

    // Create a string to store the result
    string result = "";

    // Read the matrix row by row
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // If the matrix cell is not null, append it to the result
            if (matrix[i][j] != '\0')
            {
                result += matrix[i][j];
            }
        }
    }

    // Return the encrypted message
    return result;
}

// A function to decrypt a message using the rail fence cipher
string RailFenceDecrypt(string input, int key)
{
    // Create a matrix of key rows and cipher length columns
    int rows = key;
    int cols = input.length();
    char matrix[rows][cols];

    // Initialize the matrix with null characters
    fill(&matrix[0][0], &matrix[0][0] + rows * cols, '\0');

    // Mark the spots where the cipher characters should be placed
    int row = 0;      // The current row
    int col = 0;      // The current column
    bool down = true; // The direction of movement
    for (int i = 0; i < cols; i++)
    {
        // Mark the current spot with a dummy character
        matrix[row][col] = '*';
        col++;

        // Change the direction if we reach the top or bottom rail
        if (row == 0)
        {
            down = true;
        }
        if (row == rows - 1)
        {
            down = false;
        }

        // Move to the next row according to the direction
        if (down)
        {
            row++;
        }
        else
        {
            row--;
        }
    }

    // Fill the matrix with the cipher characters row by row
    int index = 0; // The index of the cipher string
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // If the matrix cell is marked, replace it with the cipher character
            if (matrix[i][j] == '*')
            {
                matrix[i][j] = input[index];
                index++;
            }
        }
    }

    // Create a string to store the result
    string result = "";

    // Read the matrix diagonally
    row = 0;
    col = 0;
    down = true;
    for (int i = 0; i < cols; i++)
    {
        // Append the current character to the result
        result += matrix[row][col];
        col++;

        // Change the direction if we reach the top or bottom rail
        if (row == 0)
        {
            down = true;
        }
        if (row == rows - 1)
        {
            down = false;
        }

        // Move to the next row according to the direction
        if (down)
        {
            row++;
        }
        else
        {
            row--;
        }
    }

    // Return the decrypted message
    return result;
}

// A function to test the encryption and decryption functions
bool RailFenceCipherTest(string input, int key, string expectedOutput)
{
    cout << "Key: " << key << endl;
    // Encrypt the message
    string encoded = RailFenceEncrypt(input, key);

    // Print the results
    cout << "Original: " << input << endl;
    cout << "Encoded: " << encoded << endl;

    if (encoded != expectedOutput)
        return false;

    // Decrypt the cipher
    string decoded = RailFenceDecrypt(encoded, key);

    cout << "Encoded: " << encoded << endl;
    cout << "Decoded: " << decoded << endl;

    if (decoded != input)
        return false;

    return true;
}
