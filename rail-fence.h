// rail-fence.h

#ifndef RAILFENCE_H
#define RAILFENCE_H

#include <string>

using namespace std;

/**
 * @brief Function that encrypts a string using the rail fence cypher.
 * 
 * @param input String to be encrypted
 * @param key Number of rails in the fence
 * @return string Encrypted string
 */
string RailFenceEncrypt(string input, int key); 

/**
 * @brief Function that decrypts a string using the rail fence cypher.
 * 
 * @param input String to be decrypted
 * @param key Number of rails in the fence
 * @return string Plain text decrypted string 
 */
string RailFenceDecrypt(string input, int key);

/**
 * @brief 
 * 
 * @param input String to encrypt.
 * @param key Number of rails in the fence.
 * @param expectedOutput Expected encrypted string.
 * @return true if all encrypts and decrypts correctly 
 * @return false if either encryption or decryption fails
 */
bool RailFenceCipherTest(string input, int key, string expectedOutput);

#endif // RAILFENCE_H