#include <iostream>
using namespace std;
class Stack {
private:
    int* stackData; // Dynamic array for storing elements
    int capacity; // Current capacity of the stack
    int top; // Index of the top element in the stack
    // Function to resize the array when it reaches capacity
    void resize() {
        int newCapacity = capacity * 2;
        int* newStackData = new int[newCapacity];
        // Copy old elements to the new array
        for (int i = 0; i < capacity; i++) {
            newStackData[i] = stackData[i];
        }
        delete[] stackData; // Free old array memorystackData = newStackData;
        capacity = newCapacity;
    }
public:
    // Constructor
    Stack(int initialCapacity = 2) : capacity(initialCapacity), top(-1) {
        stackData = new int[capacity];
    }
    // Destructor to free up memory
    ~Stack() {
        delete[] stackData;
    }
    // Push an element onto the stack
    void push(int value) {
        // Resize the array if the stack is full
        if (top + 1 == capacity) {
            resize();
        }
        stackData[++top] = value;
        cout << "Pushed " << value << " onto the stack.\n";
    }
    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        cout << "Popped " << stackData[top--] << " from the stack.\n";
    }
    // Peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek.\n";
            return -1; // Return -1 or any other error value
        }
        return stackData[top];
    }
    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};
int main() {
    Stack s;
    s.push(10);s.push(20);
    cout << "Top element is: " << s.peek() << endl; // Should display 20
    s.push(30);
    s.pop();
    cout << "Top element after pop is: " << s.peek() << endl; // Should display 20
    s.pop();
    s.pop();
    s.pop(); // Should indicate stack is empty
    return 0;
}
