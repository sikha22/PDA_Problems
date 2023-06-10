/*******
Problem Statement
You are given a QUEUE containing ‘N’ integers and an integer ‘K’. You need to reverse the order of the first ‘K’ elements of the queue, leaving the other elements in the same relative order.
You can only use the standard operations of the QUEUE STL:
1. enqueue(x) : Adds an item x to rear of the queue
2. dequeue() : Removes an item from front of the queue
3. size() : Returns number of elements in the queue.
4. front() : Finds the front element.
For Example:
Let the given queue be { 1, 2, 3, 4, 5 } and K be 3.
You need to reverse the first K integers of Queue which are 1, 2, and 3.
Thus, the final response will be { 3, 2, 1, 4, 5 }.
********/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int> reverseElements(queue<int> q, int k) {
    stack<int> s;
    
    // Step 1: Dequeue the first 'K' elements and push them onto the stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    // Step 2: Enqueue the elements from the stack back into the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    // Step 3: Rotate the remaining elements to maintain relative order
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }
    
    return q;
}

int main() {
    queue<int> q;
    int n, k;

    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    
    cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        q.push(num);
    }
    
    cout << "Enter the value of K: ";
    cin >> k;

    queue<int> reversedQueue = reverseElements(q, k);
    
    cout << "Reversed queue: ";
    while (!reversedQueue.empty()) {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }
    
    return 0;
}
