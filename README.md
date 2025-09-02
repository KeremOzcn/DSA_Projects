# C++ Data Structures and Algorithms Projects

This repository contains a collection of fundamental data structures and algorithms implemented in C++. These projects were developed to practice and demonstrate core computer science concepts.

## Implemented Data Structures

This repository includes the following implementations:

1.  **Circular Queue (`Queue.cpp`)**: A queue implementation that uses a fixed-size array in a circular manner to efficiently manage elements.
2.  **Stack (`Stack.cpp`)**: A dynamic stack implementation that automatically resizes itself when its capacity is reached.
3.  **Two Stacks in One Array (`TwoStack.cpp`)**: A space-efficient implementation of two stacks using a single array. One stack grows from the beginning, while the other grows from the end.
4.  **To-Do List using Linked List (`ToDoList.cpp`)**: A simple command-line to-do list application built with a singly linked list. It allows users to add, remove, and mark tasks as complete.
5.  **Music Playlist using Doubly Linked List (`MusicLinkedList.cpp`)**: A music playlist manager implemented with a doubly linked list. It supports adding, removing, navigating (next/previous), and displaying songs.

## Project Descriptions

### 1. Circular Queue

-   **File**: `Queue.cpp`
-   **Description**: This program implements a generic circular queue. A circular queue is a linear data structure that follows the First-In-First-Out (FIFO) principle, but the last position is connected back to the first position to form a circle, making it more memory-efficient than a standard queue.
-   **Features**:
    -   Enqueue: Add an element to the rear of the queue.
    -   Dequeue: Remove an element from the front of the queue.
    -   `isFull()`: Check if the queue is full.
    -   `isEmpty()`: Check if the queue is empty.
    -   `displayQueue()`: Display all elements in the queue.

### 2. Dynamic Stack

-   **File**: `Stack.cpp`
-   **Description**: This is an implementation of a stack data structure that follows the Last-In-First-Out (LIFO) principle. The underlying storage is a dynamic array that doubles in size when it becomes full, allowing for an arbitrary number of elements.
-   **Features**:
    -   `push()`: Add an element to the top of the stack.
    -   `pop()`: Remove the top element from the stack.
    -   `peek()`: View the top element without removing it.
    -   `isEmpty()`: Check if the stack is empty.

### 3. Two Stacks in One Array

-   **File**: `TwoStack.cpp`
-   **Description**: An optimized implementation that manages two separate stacks within a single contiguous array. This approach saves space by allowing the stacks to grow towards each other from opposite ends of the array.
-   **Features**:
    -   `push1()` / `push2()`: Add elements to the first and second stack, respectively.
    -   `pop1()` / `pop2()`: Remove elements from the first and second stack.
    -   Efficiently handles stack overflow by checking if there is space between the two stack tops.

### 4. To-Do List (Linked List)

-   **File**: `ToDoList.cpp`
-   **Description**: A console-based to-do list application. Each task is a node in a singly linked list. This project demonstrates dynamic memory allocation and pointer manipulation.
-   **Features**:
    -   Add a new task to the list.
    -   Remove a task by its ID.
    -   Mark a task as completed.
    -   Display all tasks with their status (Completed/Not Completed).

### 5. Music Playlist (Doubly Linked List)

-   **File**: `MusicLinkedList.cpp`
-   **Description**: A command-line interface for managing a music playlist. It uses a doubly linked list, which allows for easy traversal in both forward and backward directions.
-   **Features**:
    -   Add and insert songs anywhere in the playlist.
    -   Remove songs from the beginning, end, or a specific position.
    -   Play the next and previous songs.
    -   Display the current playlist in forward or reverse order.
    -   Search for a song by title.

## How to Compile and Run

You can compile and run these projects using a C++ compiler like g++.

1.  **Open your terminal or command prompt.**
2.  **Navigate to the directory where the source files are located.**
3.  **Use the following command to compile a specific file (e.g., `Queue.cpp`):**

    ```bash
    g++ Queue.cpp -o Queue
    ```

4.  **To run the compiled program, use:**

    ```bash
    ./Queue
    ```

    Replace `Queue.cpp` and `Queue` with the name of the file you wish to compile and run.
