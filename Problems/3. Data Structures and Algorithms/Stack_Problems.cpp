#include <iostream>
#include <stack>
#include <queue>
using std::cout; using std::endl; using std::stack; using std::queue;

// Find min/max element
int findMin(stack<int> s) {
    if (s.empty())
        throw std::runtime_error("Stack is empty!");

    int min = s.top();
    s.pop();

    while (!s.empty()) {
        if (s.top() < min) {
            min = s.top();
        }

        s.pop();
    }

    return min;
}

// Remove even/odd elements
void removeEven(stack<int>& s) {
    stack<int> tempStack;

    while (!s.empty()) {
        int val = s.top();
        s.pop();

        if (val % 2 == 1)
            tempStack.push(val);
    }

    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Balanced Parentheses
bool areBracketsBalanced(const char* str) {
    stack<char> brackets;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            brackets.push(str[i]);
        }
        else {
            if (brackets.empty()) return false;

            if (str[i] == ')' && brackets.top() != '(' ||
                str[i] == ']' && brackets.top() != '[' ||
                str[i] == '}' && brackets.top() != '{') return false;

            else brackets.pop();
        }
    }
    
    return brackets.empty();
}

// Sort a Stack
stack<int> sort(stack<int>& s) {
    stack<int> tempStack;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top()); 
            tempStack.pop();    
        }

        tempStack.push(temp); 
    }

    return tempStack;
}

// Reverse a Stack
void reverse(stack<int> s) {
    queue<int> q;

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
 
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
}

int main() {

    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(5);

    stack<int> sorted = sort(s);

    while (!sorted.empty()) {
        cout << sorted.top() << " ";
        sorted.pop();
    }

    cout << endl;

    return 0;
}