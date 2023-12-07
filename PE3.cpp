/*
Chris Samuel Salcedo
Ann Junah Suyman
2022-05055
2022-09089

CMSC 122
Programming Exercise 03: Stack Implementation (Array)

This program implements stack implementation.
*/

#include <iostream>
#include <cstring>

using namespace std;

// Define a Node class to represent elements in the stack.
class Node {
public:
    string data;
    Node* next;
};

// Define a Stack class that uses a linked list to implement a stack.
class Stack {
private:
    Node* top_node;  // Pointer to the top node of the stack.
    int size;        // Add a size variable to keep track of the number of items.
public:
    // Constructor to initialize the stack.
    Stack() {
        top_node = nullptr;
        size = 0;  // Initialize size to 0.
    }

    // Add a method to check if the stack is full.
    bool is_full() {
        return size >= 10;  // Returns true if the stack is full (size is 10).
    }

    // Method to push an item onto the stack.
    void push(string x) {
        if (is_full()) {
            cout << "The STACK is FULL. Cannot add kitchenware." << endl << endl;
            return;  // Return without adding if the stack is full.
        }

        // Create a new Node and add it to the top of the stack.
        Node* new_node = new Node;
        new_node->data = x;
        new_node->next = top_node;
        top_node = new_node;
        size++;  // Increment size when adding an item.
    }

    // Method to pop (remove and return) the item from the top of the stack.
    string pop() {
        if (is_empty()) {
            return "";
        }
        string data = top_node->data;
        Node* temp = top_node;
        top_node = top_node->next;
        delete temp;
        size--;  // Decrement size when removing an item.
        return data;
    }

    // Method to check if the stack is empty.
    bool is_empty() {
        return top_node == nullptr;
    }

    // Method to return the top item of the stack without removing it.
    string top() {
        if (is_empty()) {
            return "";
        }
        return top_node->data;
    }

    // Method to delete all items in the stack.
    void make_null() {
        while (!is_empty()) {
            pop();
        }
    }
};

int main() {
    Stack kitchenware_stack;  // Create an instance of the Stack class to store kitchenware.
    int choice;
    string kitchenware;

    // Main menu loop for the kitchenware washing machine program.
    while (true) {
        cout << "Kitchenware Washing Machine" << endl;
        cout << "  [1] Add kitchenware" << endl;
        cout << "  [2] Wash kitchenware" << endl;
        cout << "  [3] Top kitchenware" << endl;
        cout << "  [4] Wash all" << endl;
        cout << "  [0] Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;
        cin.ignore();

        switch (choice) {
            case 1:
                // Check if the kitchenware stack is full.
                if (kitchenware_stack.is_full()) {
                    // Display a message indicating that the stack is full and cannot add more kitchenware.
                    cout << "The STACK is FULL. Cannot add kitchenware." << endl << endl;
                    // Skip the rest of the loop and return to the menu.
                    continue;
                } else {
                    // Prompt the user to enter kitchenware to be washed.
                    cout << "Enter kitchenware to be washed: ";
                    // Read the kitchenware input from the user.
                    getline(cin, kitchenware);
                    // Push the entered kitchenware onto the stack.
                    kitchenware_stack.push(kitchenware);
                }
                break;

            case 2:
                // Check if the kitchenware stack is empty.
                if (kitchenware_stack.is_empty()) {
                    // Display a message indicating that the stack is empty and no more kitchenware to wash.
                    cout << "The STACK is EMPTY. No more kitchenware to wash." << endl << endl;
                } else {
                    // Pop (remove) the top item from the stack and indicate that it is being washed.
                    cout << kitchenware_stack.pop() << " is being washed." << endl << endl;
                }
                break;

            case 3:
                // Check if the kitchenware stack is empty.
                if (kitchenware_stack.is_empty()) {
                    // Display a message indicating that the stack is empty and no kitchenware to wash.
                    cout << "The STACK is EMPTY. No kitchenware to wash." << endl << endl;
                } else {
                    // Display the top item on the stack, indicating it is next to be washed.
                    cout << kitchenware_stack.top() << " is next to be washed." << endl << endl;
                }
                break;

            case 4:
                // Check if the kitchenware stack is empty.
                if (kitchenware_stack.is_empty()) {
                    // Display a message indicating that the stack is empty and no kitchenware to wash.
                    cout << "The STACK is EMPTY. No kitchenware to wash." << endl << endl;
                } else {
                    // Wash all kitchenware by popping and displaying each item in the stack.
                    while (!kitchenware_stack.is_empty()) {
                        cout << kitchenware_stack.pop() << " is being washed." << endl;
                    }
                    // Display a message indicating that all kitchenware has been washed.
                    cout << "All kitchenware has been washed." << endl << endl;
                }
                break;

            case 0:
                // Display a message indicating the termination of the washing machine process.
                cout << "The washing machine process has been terminated." << endl << endl;
                // Delete all items in the kitchenware stack.
                kitchenware_stack.make_null();
                return 0;

            default:
                // Display a message for an invalid choice and prompt the user to try again.
                cout << "Invalid choice. Please try again." << endl << endl;
                break;
        }
    }
}
