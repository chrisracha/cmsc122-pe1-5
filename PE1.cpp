/*
Chris Samuel Salcedo
Ann Junah Suyman
2022-05055
2022-

CMSC 122
Programming Exercise 01: List Implementation (Array)

This program implements a list ADT using an array.
*/

#include <iostream>

using namespace std;
#define MAXSIZE 10 // define max size of list

// define struct list
struct list {
    int items[MAXSIZE];
    int end;
};

// declare functions
int MENU();
void INSERT(int item, int p, struct list* L);
void DELETE(int p, struct list* L);
void DISPLAY(struct list* L);
void DELETELIST(struct list* L);

// main function
int main() {

// declare variables
struct list L;
L.end = -1;
int item, p;

// loop menu
while(1) { 
    int choice = MENU();
    switch (choice)
    {
    case (1):
        cout << "Enter item to add: ";
        cin >> item;
        cout << "Enter position to add: ";
        cin >> p;
        INSERT(item , p, &L); // pass by reference
        break;
    case (2):
        cout << "Enter position to delete: ";
        cin >> p;
        DELETE(p, &L);
        break;
    case (3):
        DISPLAY(&L);
        break;
    case (4):
        DELETELIST(&L);
        break;
    case (0):
        cout << "Progam Exited Successfully";
        return 0;
        break;
    default:
        cout << "Invalid Choice";
        break;
    }
}
return 0;
}

// define functions

// show menu
int MENU() {
    int choice;
    cout << "List MENU\n\n";
    cout << "[1] Add Item\n";
    cout << "[2] Delete Item\n";
    cout << "[3] Display List\n";
    cout << "[4] Delete List\n";
    cout << "[0] Exit Program\n\n";

    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

// insert item
void INSERT(int item, int p, struct list* L) {
    int i;
    if (L->end >= MAXSIZE) { // check if list is full
        cout << "List is full\n";
        return;
    } else if (p > L->end + 1 || p < 0) { // check if position is valid
        cout << "Invalid position\n";
        return;
    } else {
        for (i = L->end; i >= p; i--) { // shift items to the right
            L->items[i+1] = L->items[i];
        }
        // insert item at position p and increment end
        L->items[p] = item;
        L->end++;
    }
}

// delete item
void DELETE(int p, struct list* L) {
    int i;
    if (L->end < 0) { // check if list is empty
        cout << "List is empty\n";
        return;
    } else if (p > L->end || p < 0) { // check if position is valid
        cout << "Invalid position\n";
        return;
    } else {
        for (i = p; i < L->end; i++) {
            L->items[i] = L->items[i+1]; // shift items to the left
        }
        L->end--; // decrement end
    }
}

// display list
void DISPLAY(struct list* L) {
    int i;

    if (L->end < 0) {
        cout << "List is empty\n";
        return;
    } else {
        for (i = 0; i <= L->end; i++) {
            cout << L->items[i] << "\n\n"; // loop through items and display
        }
    }
}

// delete list
void DELETELIST(struct list* L) {
    L->end = -1; // set end to -1 to empty list
}