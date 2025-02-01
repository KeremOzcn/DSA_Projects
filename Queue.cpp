#include <iostream>
#include <string> // For string data type

using namespace std;

// A class to implement a circular queue
template <typename T>
class CircularQueue {
private:
    T* data;          // Pointer to dynamically allocated array for queue storage
    int front, rear;  // Indices for the front and rear of the queue
    int size;         // Number of elements currently in the queue
    int capacity;     // Maximum capacity of the queue

public:
    // Constructor to initialize the circular queue with a given capacity
    CircularQueue(int cap) {
        capacity = cap;           // Set maximum capacity
        data = new T[capacity];   // Allocate memory for the queue
        front = -1;               // Initialize front index
        rear = -1;                // Initialize rear index
        size = 0;                 // Queue is initially empty
    }

    // Destructor to release dynamically allocated memory
    ~CircularQueue() {
        delete[] data;            // Free memory allocated for the queue
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (size == 0);       // Queue is empty when size is zero
    }

    // Function to check if the queue is full
    bool isFull() {
        return (size == capacity); // Queue is full when size equals capacity
    }

    // Function to add an element (enqueue) to the queue
    void enqueue(const T& element) {
        if (isFull()) { // Check if the queue is full
            cout << "The queue is full. Cannot add more elements." << endl;
            return;
        }

        if (front == -1) front = 0; // Initialize front if the queue was previously empty
        rear = (rear + 1) % capacity; // Calculate the next rear position circularly
        data[rear] = element; // Add the element to the rear position
        size++; // Increment the size of the queue

        cout << "Element added to the queue." << endl;
    }

    // Function to remove an element (dequeue) from the queue
    void dequeue() {
        if (isEmpty()) { // Check if the queue is empty
            cout << "No elements to remove. The queue is empty." << endl;
            return;
        }

        cout << "Removing element: " << data[front] << endl; // Display the removed element
        front = (front + 1) % capacity; // Calculate the next front position circularly
        size--; // Decrement the size of the queue

        // Reset indices if the queue becomes empty
        if (size == 0) {
            front = -1;
            rear = -1;
        }
    }

    // Function to display the elements in the queue
    void displayQueue() {
        if (isEmpty()) { // Check if the queue is empty
            cout << "The queue is empty." << endl;
            return;
        }

        cout << "Elements in the queue:" << endl;
        for (int i = 0; i < size; ++i) { // Loop through the elements in the queue
            int index = (front + i) % capacity; // Calculate the circular index
            cout << (i + 1) << ". " << data[index] << endl; // Print each element with its position
        }
    }
};

int main() {
    int queueCapacity; // Variable to store the size of the queue

    cout << "Enter the size of the queue: ";
    cin >> queueCapacity; // Input the maximum capacity of the queue

    CircularQueue<string> queue(queueCapacity); // Create a CircularQueue object for strings

    int choice;         // Variable to store user's menu choice
    string element;     // Variable to store user input for enqueue operation

    do {
        // Display menu options
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Add Element\n";
        cout << "2. Remove Element\n";
        cout << "3. Display Queue\n";
        cout << "4. Check if Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Input the user's choice

        switch (choice) {
            case 1: // Add element to the queue
                cout << "Enter element to add: ";
                cin.ignore(); // Ignore newline from previous input
                getline(cin, element); // Input the element (handles spaces)
                queue.enqueue(element); // Call enqueue function
                break;

            case 2: // Remove element from the queue
                queue.dequeue(); // Call dequeue function
                break;

            case 3: // Display the queue
                queue.displayQueue(); // Call displayQueue function
                break;

            case 4: // Check if the queue is empty
                if (queue.isEmpty()) {
                    cout << "The queue is empty." << endl;
                } else {
                    cout << "The queue is not empty." << endl;
                }
                break;

            case 5: // Exit the program
                cout << "Exiting the program." << endl;
                break;

            default: // Handle invalid choices
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0;
}
