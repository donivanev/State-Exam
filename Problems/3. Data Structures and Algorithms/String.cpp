#include <iostream>
#include <string>
using std::cout; using std::string; using std::to_string; using std::stoi;

int main() {

    string s; // empty string
    s = "";
    string s2 = "hello"; // from C-string
    string s3("world"); // constructor

    s2[0]; // 'h', no bounds check
    s2.at(1); // 'e', bounds checking
    s2.front(); // 'h'
    s2.back(); // 'o'

    s2.size(); // 5
    s2.length(); // same as size()
    s2.empty(); // false

    s2 += " world"; // append
    s2.append("!!!"); // append
    s2.insert(0, "Say: "); // insert at index
    s2.erase(0, 5); // erase 5 chars from index 0
    s2.replace(0, 3, "Hey"); // replace part of string
    s2.clear(); // make empty

    s2.find("lo"); // returns position or std::string::npos
    s2.substr(2, 3); // substring from index 2, length 3
    s2 == "hello"; // true if equal
    s2.compare("hello"); // 0 if equal

    string str = to_string(123); // "123"
    int x = stoi("42"); // 42

    string text = "The quick brown fox";

    size_t pos = text.find("brown"); // 10
    if (pos != string::npos) {
        cout << "Found at " << pos;
    }

    string text = "abcdef";
    string part = text.substr(2, 3);  // "cde"

    return 0;
}