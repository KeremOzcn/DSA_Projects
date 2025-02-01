#include <iostream>
using namespace std;
// This class implements two stacks using a single array
class TwoStacks {
private:
int *arr; // Array to store stack elements
int size; // Total size of the array
int top1; // Top index for the first stack
int top2; // Top index for the second stack (starts from the end of the array)
public:
// Constructor: Initializes the two stacks within a single array
TwoStacks(int n) {
size = n; // Set the total size of the array
arr = new int[n]; // Dynamically allocate memory for the array
top1 = -1; // Initialize the first stack's top to -1 (empty)
top2 = size; // Initialize the second stack's top to size (empty)
}// Function to push an element onto the first stack
void push1(int x) {
// Check if there is space between top1 and top2
if (top1 < top2 - 1) {
top1++; // Move the top index of the first stack forward
arr[top1] = x; // Insert the element into the first stack
} else {
// No space left for the first stack
cout << "Stack Overflow in Stack 1\n";
}
}
// Function to push an element onto the second stack
void push2(int x) {
// Check if there is space between top1 and top2
if (top1 < top2 - 1) {
top2--; // Move the top index of the second stack backward
arr[top2] = x; // Insert the element into the second stack
} else {
// No space left for the second stack
cout << "Stack Overflow in Stack 2\n";
}
}
// Function to pop an element from the first stack
int pop1() {
// Check if the first stack is not empty
if (top1 >= 0) {
int x = arr[top1]; // Retrieve the top element of the first stack
top1--; // Move the top index backwardreturn x; // Return the popped element
} else {
// First stack is empty
cout << "Stack Underflow in Stack 1\n";
return -1; // Return -1 to indicate underflow
}
}
// Function to pop an element from the second stack
int pop2() {
// Check if the second stack is not empty
if (top2 < size) {
int x = arr[top2]; // Retrieve the top element of the second stack
top2++; // Move the top index forward
return x; // Return the popped element
} else {
// Second stack is empty
cout << "Stack Underflow in Stack 2\n";
return -1; // Return -1 to indicate underflow
}
}
// Function to display the current state of both stacks
void display() {
// Display elements in the first stack
cout << "Stack 1 elements: ";
for (int i = 0; i <= top1; i++) {
cout << arr[i] << " ";
}
cout << "\n";// Display elements in the second stack
cout << "Stack 2 elements: ";
for (int i = size - 1; i >= top2; i--) {
cout << arr[i] << " ";
}
cout << "\n";
}
};
int main() {
// Create a TwoStacks object with a total size of 10
TwoStacks ts(10);
// Push elements onto the first stack
ts.push1(1);
ts.push1(2);
ts.push1(3);
// Push elements onto the second stack
ts.push2(10);
ts.push2(9);
ts.push2(8);
// Display the current state of both stacks
ts.display();
// Pop elements from the first and second stacks
cout << "Popped from Stack 1: " << ts.pop1() << "\n"; // Remove top element of Stack 1
cout << "Popped from Stack 2: " << ts.pop2() << "\n"; // Remove top element of Stack 2
// Display the state of both stacks after poppingts.display();
return 0;
}
