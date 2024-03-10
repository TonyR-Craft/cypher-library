#include <iostream>
#include "rot13.h"
#include "rail-fence.h"

using namespace std;

// ROT13 Cypher
extern "C" __declspec(dllexport) string encryptRot13(string& input) {
    return Rot13Encrypt(input);
}

extern "C" __declspec(dllexport) string decryptRot13(string& input) {
    return Rot13Decrypt(input);
}

extern "C" __declspec(dllexport) bool testRot13(string input, string expectedOutput) {
    return Rot13Test(input, expectedOutput);
}

// Rail Fence Cypher
extern "C" __declspec(dllexport) string encryptRailFence(string input, int key) {
    return RailFenceEncrypt(input, key);
}

extern "C" __declspec(dllexport) string decryptRailFence(string input, int key) {
    return RailFenceDecrypt(input, key);
}

extern "C" __declspec(dllexport) bool testRailFenceCipher(string input, int key, string expectedOutput) {
    return RailFenceCipherTest(input, key, expectedOutput);
}