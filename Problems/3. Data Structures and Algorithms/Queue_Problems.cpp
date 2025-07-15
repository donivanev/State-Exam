#include <iostream>
#include <stack>
#include <queue>
using std::cout; using std::stack; using std::queue;

void print(queue<int>& q) {
    for (int i = 0; i < q.size(); i++) {
        int curr = q.front();
        cout << curr << " ";
        q.push(curr);
        q.pop();
    }
}

// Find min/max element
int findMin(queue<int>& q) {
    int min = q.front();

    for (int i = 0; i < q.size(); i++) {
        int curr = q.front();

        if (min > q.front()) {
            min = q.front();
        }
        
        q.push(curr);
        q.pop();
    }

    return min;
}

// Remove even/odd elements
void removeOddElements(queue<int>& q) {
    int size = q.size();

    for (int i = 0; i < size; i++) {
        int curr = q.front();

        if (curr % 2 == 0) {
            q.push(curr);
        }
        
        q.pop();
    }
}

// Merge Queues
void mergeQueues(queue<int>& q, queue<int>& q1, queue<int>& q2) {
    int size = q1.size() + q2.size();
    int size1 = q1.size();

    for (int i = 0; i < size; i++) {
        if (i < size1) {
            q.push(q1.front());
            q1.pop();
        }
        else {
            q.push(q2.front());
            q2.pop();
        }
    }
}

// Sort a Queue - not possible

// Reverse a Queue
void reverse(queue<int>& q) {
    stack<int> s;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop(); 
    }
}

int main() {

    queue<int> q;
    q.push(6);
    q.push(2);
    q.push(9);
    q.push(1);
    q.push(14);

    print(q);
    cout << findMin(q);
    
    removeOddElements(q);
    print(q);

    return 0;
}