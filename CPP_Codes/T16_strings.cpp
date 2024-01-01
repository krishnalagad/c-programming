#include <iostream>

int main() {
    // Constructors
    std::string str1;
    std::string str2("Hello");
    std::string str3 = "World";
    std::string str4 = str2; // Copy constructor

    // String operations
    std::string result = str2 + str3; // Concatenation
    std::cout<<"\nConcatination: "<<result;
    str2 += "!"; // Appending
    std::cout<<"\nAppending: "<<str2;
    int length = str2.length(); // Length
    std::cout<<"\nLength: "<<length;
    char firstChar = str2[0]; // Accessing Characters
    std::cout<<"\nCharacter: "<<firstChar;

    // String comparison
    if (str2 == str3) {
        std::cout << "\nStrings are equal." << std::endl;
    }

    // Lexicographical comparison
    if (str2 < str3) {
        std::cout << "\nstr2 comes before str3." << std::endl;
    }

    // Searching and substring
    std::size_t found = str2.find("lo"); // Finding a substring
    std::string sub = str2.substr(1, 3); // Extracting a substring
    std::cout<<"\nSubstring: "<<sub;

    // Modifying
    str2.replace(1, 3, "xyz"); // Replacing substring
    std::cout<<"\nReplace: "<<str2;
    str2.erase(1, 3); // Erasing substring
    std::cout<<"\nErase: "<<str2;

    // Conversion
    const char* cStr = str2.c_str(); // C++ String to C-Style String
    std::string cppStr = "Hello";
    cStr = cppStr.c_str(); // C-Style String to C++ String

    // Input and Output
    std::cin >> str2; // Input from Console
    std::cout << str2; // Output to Console

    // Miscellaneous
    str2.clear(); // Clearing the string
    if (str2.empty()) {
        std::cout << "String is empty." << std::endl;
    }

    return 0;
}
