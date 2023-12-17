/*
Chris Samuel Salcedo
Ann Junah Suyman
2022-05055
2022-09089

CMSC 122
Programming Exercise 01: List Implementation (Array)

This program implements a list ADT using an array implementation.
*/
#include <iostream>

#define MAXSIZE 10 // define max size of list

using namespace std;

// define struct list
struct list {
    int items[MAXSIZE];
    int end;
};

// declare functions
int MENU();
bool INSERT(int item, int p, struct list* L);
bool DELETE(int p, struct list* L);
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
        cout << "Where to add the item?" << endl;
        cout << "[1] Start of the list\n[2] End of the list\n[3] Specific position\n[0] Cancel" << endl << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case (1):
            p = 0;
            cout << "Enter item to add: ";
            cin >> item;
            if(!INSERT(item , p, &L)) { // pass by reference
            cout << "Insertion failed\n";
            }
            break;
        case (2):
            p = L.end + 1;
            cout << "Enter item to add: ";
            cin >> item;
            if(!INSERT(item , p, &L)) { // pass by reference
            cout << "Insertion failed\n";
            }
            break;
        case (3):
            cout << "Enter position to add: ";
            cin >> p;
            cout << "Enter item to add: ";
            cin >> item;
            if(!INSERT(item , p, &L)) // pass by reference
                cout << "Insertion failed\n";
            break;
                case (0):
            break;
        default:
            cout << "Invalid Choice";
            break;
        }
        break;
    case (2):
        cout << "Enter position to delete: ";
        cin >> p;
        if(!DELETE(p, &L))
            cout << "Deletion failed\n";
        break;
    case (3):
        DISPLAY(&L);
        break;
    case (4):
        DELETELIST(&L);
        break;
    case (0):
        cout << "Program Exited Successfully";
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
    cout << "\nList MENU" << endl << endl;
    cout << "[1] Add Item" << endl;
    cout << "[2] Delete Item" << endl;
    cout << "[3] Display List" << endl;
    cout << "[4] Delete List" << endl;
    cout << "[0] Exit Program" << endl << endl;

    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

// insert item
bool INSERT(int item, int p, struct list* L) {
    if (L->end + 1 >= MAXSIZE) { // check if list is full
        cout << "List is full" << endl;
        return false;
    } else if (p > L->end + 1 || p < 0) { // check if position is valid
        return false;
    } else {
        for (int i = L->end; i >= p; i--) { // shift items to the right
            L->items[i+1] = L->items[i];
        }
        // insert item at position p and increment end
        L->items[p] = item;
        L->end++;
        return true;
    }
}

// delete item
bool DELETE(int p, struct list* L) {
    int item;
    item = L->items[p];
    if (L->end < 0) { // check if list is empty
        return false;
    } else if (p > L->end || p < 0) { // check if position is valid
        return false;
    } else {
        for (int i = p; i < L->end; i++) {
            L->items[i] = L->items[i+1]; // shift items to the left
        }
        L->end--; // decrement end
        cout << "The element " << item <<  ", which is at position " << p << " has been deleted." << endl;
        return true;
    }
}

// display list
void DISPLAY(struct list* L) {
    if (L->end < 0) {
        cout << "List is empty" << endl;
        return;
    } else {
        cout << endl;
        for (int i = 0; i <= L->end; i++) {
            cout << "[" << i << "] " << flush;
            cout << L->items[i] << endl; // loop through items and display
        }
    }
}

// delete list
void DELETELIST(struct list* L) {
    L->end = -1; // set end to -1 to empty list
    cout << "The list has been emptied!" << endl;
}
