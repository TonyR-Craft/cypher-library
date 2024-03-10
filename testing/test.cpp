#include <windows.h>
#include <iostream>

using namespace std;

/**
 * @brief Function Manager class that loads a dll and gets references 
 *        to it's exported functions
 * 
 */
class FunctionManager
{
public:
    FunctionManager(const char *dllPath)
    {
        hDLL = LoadLibraryA(dllPath);
        if (hDLL == nullptr)
        {
            cerr << "Error loading DLL: " << GetLastError() << endl;
            // Handle the error (e.g., throw an exception or exit)
        }
    }

    ~FunctionManager()
    {
        if (hDLL != nullptr)
        {
            FreeLibrary(hDLL);
        }
    }

    // Get a function pointer from the DLL
    template <typename FuncType>
    FuncType GetFunction(const char *functionName)
    {
        return reinterpret_cast<FuncType>(GetProcAddress(hDLL, functionName));
    }

    // Call a function from the DLL with any number of arguments
    template <typename FuncType, typename... Args>
    void CallDLLFunction(FuncType func, Args &&...args)
    {
        func(forward<Args>(args)...); // Call the function
    }

private:
    HMODULE hDLL;
};

/**
 * @brief Main entry point for the test suite.  Tests all the exported functions.
 * 
 * @return int 
 */
int main()
{
    const char *cryptoLibraryPath = "../crypto-library.dll"; // Replace with actual DLL path

    FunctionManager manager(cryptoLibraryPath);

    // Test ROT 13 Cypher
    // Get a function pointer to a function named "encodeRot13"
    auto encryptRot13 = manager.GetFunction<string (*)(string &)>("encryptRot13");
    if (!encryptRot13)
        cerr << "Function encodeRot13 not found in DLL." << endl;

    // Get a function pointer to a function named "decodeRot13"
    auto decryptRot13 = manager.GetFunction<string (*)(string &)>("decryptRot13");
    if (!decryptRot13)
        cerr << "Function decodeRot13 not found in DLL." << endl;

    // Get a function pointer to a function named "testRot13"
    auto testRot13 = manager.GetFunction<bool (*)(string, string)>("testRot13");
    if (!testRot13)
        cerr << "Function testRot13 not found in DLL." << endl;

    if (testRot13("Hello, World!", "Uryyb, Jbeyq!"))
    {
        cout << "Test Passed: "
             << "Hello, World!" << endl;
    }
    else
    {
        cout << "Test Failed: "
             << "Hello, World!" << endl;
    }

    // Test Rail Fence Cypher
    // Get a function pointer to a function named "encryptRailFence"
    auto encryptRailFence = manager.GetFunction<string (*)(string, int)>("encryptRailFence");
    if (!encryptRailFence)
        cerr << "Function encryptRailFence not found in DLL." << endl;

    // Get a function pointer to a function named "decryptRailFence"
    auto decryptRailFence = manager.GetFunction<string (*)(string, int)>("decryptRailFence");
    if (!decryptRailFence)
        cerr << "Function decryptRailFence not found in DLL." << endl;

    // Get a function pointer to a function named "testRailFenceCipher"
    auto testRailFenceCipher = manager.GetFunction<bool (*)(string, int, string)>("testRailFenceCipher");
    if (!testRailFenceCipher)
        cerr << "Function testRot13 not found in DLL." << endl;

    if (testRailFenceCipher("HELLOWORLD", 3, "HOLELWRDLO"))
    {
        cout << "Test Passed: "
             << "HELLOWORLD" << endl;
    }
    else
    {
        cout << "Test Failed: "
             << "HELLOWORLD" << endl;
    }

    return 0;
}
