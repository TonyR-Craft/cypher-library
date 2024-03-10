# cypher-library
This is a cypher library written in C++.

## Exported Functions
### ROT13 Cypher
- string encryptRot13(string& input)
- string decryptRot13(string& input)
- bool testRot13(string input, string expectedOutput)

### Rail Fence Cypher
- string encryptRailFence(string input, int key)
- string decryptRailFence(string input, int key)
- bool testRailFenceCipher(string input, int key, string expectedOutput)
