/*
Salcedo, Chris Samuel
Suyman, Ann Junah
2022-05055
2022-09089

CMSC 122
Programming Exercise 02: List Implementation (Linked-list)

This program implements a list ADT using linked lists implementation.
*/
#include <iostream>

using namespace std;

// declare functions
int length(struct node* head); // returns length of list
void MENU();
bool ADD(int item, int p, struct node*& head, struct node*& tail);
bool DELETE(int p, struct node*& head);
void DISPLAY(struct node* head);
void DELETELIST(struct node*& head);

// define struct node
struct node {
    int item;
    struct node *next;

    // constructor
    node(int item) {
        this->item = item;
        this->next = NULL;
    }
};

int main() {
    struct node *head = NULL; // initialize head pointer to NULL
    struct node *tail = NULL; // initialize tail pointer to NULL

    while(1) { // loop menu
        MENU();
        int choice;
        cin >> choice;
        // switch case for menu choices
        switch (choice)
        {
        case (1):
            int item, p;
            // switch case for add choices
            do {
            cout << "\nWhere to add the item?" << endl;
            cout << "[1] Start of the list\n[2] End of the list\n[3] Specific position\n[0] Cancel" << endl << endl;
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice)
            {
            case (1):
                p = 0;
                break;
            case (2):
                p = length(head);
                break;
            case (3):
                cout << "Enter position to add: ";
                cin >> p;
                break;
            case (0):
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
            }
            } while (choice < 0 || choice > 3);
            cout << "Enter item to add: ";
            cin >> item;
            if(!ADD(item , p, head, tail)) {
                cout << "Insertion failed\n";
            };
            break;
        case (2):
            cout << "\nEnter position to delete: ";
            cin >> p;
            if(!DELETE(p, head)) {
                cout << "Deletion failed\n";
            };
            break;
        case (3):
            DISPLAY(head);
            break;
        case (4):
            DELETELIST(head);
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

int length(struct node* head) {
    int length = 0;
    struct node* current;

    for(current = head; current != NULL; current = current->next) { // traverse through list
        length++; // increment length for every node
    }

    return length;
}

void MENU() {
    cout << "\nLIST MENU" << endl;
    cout << "\n[1] Add Item" << endl;
    cout << "[2] Delete Item" << endl;
    cout << "[3] Display List" << endl;
    cout << "[4] Delete List" << endl;
    cout << "[0] Exit" << endl << endl;
    cout << "Enter Choice: ";
}

bool ADD(int item, int p, struct node*& head, struct node*& tail) {

    if (p < 0 || p > length(head)) { // check if position is valid
        cout << "Invalid position!";
        return false;
    }

    struct node *newNode = new node(item); //  create new node

    if (newNode == NULL) {
        return false; // error allocating memory
    }

    if (head == NULL) {
        head = tail = newNode; // update both head and tail
        return true;
    } else if (p == 0) { // insert at start
        newNode->next = head;
        head = newNode; // update head
        return true;
    } else if (p >= length(head)) { // insert at end
        tail->next = newNode; 
        tail = newNode; // update tail
        return true;
    } else { // insert at specific position
        struct node *temp = head;
        // traverse to node before the node to be inserted
        for (int i = 0; i < p - 1; i++) {
            temp = temp->next; 
        }

        newNode->next = temp->next;  // update next pointer of new node
        temp->next = newNode; // update next pointer of node before the node to be inserted
        return true;
    }

    return false;
}

bool DELETE(int p, struct node*& head) {

    if (p < 0 || p >= length(head)) {
        cout << "Invalid position!" << endl;
        return false;
    }

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return false;
    } else if (p == 0) { // delete first node
        struct node *temp = head; 
        head = head->next; // update head
        delete temp; 
        return true;
    } else { // delete specific position
        struct node *temp = head;

        // traverse to node before the node to be deleted
        for (int i = 0; i < p - 1; i++) {
            temp = temp->next;  
        }

        struct node *nodeToDelete = temp->next;  // node to be deleted
        temp->next = temp->next->next; // update next pointer of node before the node to be deleted

        int item = nodeToDelete->item; // get item to be deleted
        delete nodeToDelete; 

        cout << "The element " << item <<  ", which is at position " << p << " has been deleted." << endl;

        return true;
    }
    return false;
}

void DISPLAY(struct node* head) {
    int i = 0;
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        struct node *temp = head; // set temp to head

        while (temp != NULL) {
            cout << "[" << i << "] " << temp->item << endl; // display item 
            temp = temp->next;  // traverse to next node
            i++;
        }
    }
}

void DELETELIST(struct node*& head) {
    while(head != NULL){
       struct node* temp=head->next; // set temp to next node
       delete head; // delete current node
       head=temp; // set head to next node
    }
    cout << "The list has been emptied!" << endl;
}