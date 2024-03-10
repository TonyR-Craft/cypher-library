// rot13.h

#ifndef ROT13_H
#define ROT13_H

#include <string>

using namespace std;

/**
 * @brief Function that uses ROT13 cypher to encrypt a string.
 * 
 * @param input String to be encrypted
 * @return string Encrypted string.
 */
string Rot13Encrypt(string& input); 

/**
 * @brief Function that decrypts an encrypted ROT13 cypher string
 * 
 * @param input ROT13 encrypted string 
 * @return string Plain text decrypted string.
 */
string Rot13Decrypt(string& input); 

/**
 * @brief 
 * 
 * @param input String to encrypt.
 * @param expectedOutput Expected encrypted string.
 * @return true if all encrypts and decrypts correctly 
 * @return false if either encryption or decryption fails
 */
bool Rot13Test(string input, string expectedOutput);

#endif // ROT13_H