#include <iostream>
#include <vector>
using std::cout; using std::vector;

int main() {

    vector<int> v; // empty vector of ints
    vector<int> v2(5, 10); // vector with 5 elements, all initialized to 10
    vector<int> v3 = {1, 2, 3, 4, 5}; // vector initialized with list

    v.empty();
    v.size();

    v.front();
    v.back();

    v.push_back(1);
    v.push_back(2);
    v.pop_back();
    
    v.insert(v.begin() + 2, 35); // v.insert(2, 35) is wrong, expects iterators
    v.erase(v.begin()); // v.erase(3) is wrong, expects iterators

    cout << v.at(2);

    // Range-based for loop
    for (int x : v)
        cout << x << " ";

    // Iterator-based loop
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    return 0;
}