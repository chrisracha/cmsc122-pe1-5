/*
Chris Samuel Salcedo
Ann Junah Suyman
2022-05055
2022-09089

CMSC 122
Programming Exercise 07: Queue Implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // maximum size of the queue
#define LEN 50 // maximum length of each string

// A structure to represent a queue cell
struct queue_cell {
    char name[LEN]; // customer name
    char order[LEN]; // customer order
};

// A structure to represent a queue
struct queue {
    int front, rear, size; // indexes for front, rear and size of the queue
    struct queue_cell* array; // array of queue cells
};

// prototype functions
int empty(struct queue* q);
int full(struct queue* q);
void enqueue(struct queue* q, char* name, char* order);
struct queue_cell dequeue(struct queue* q);
void display_menu();
struct queue_cell front(struct queue* q);
void handle_choice(struct queue* q, int choice);

// A function to create an empty queue
struct queue* init() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue)); // allocate memory for the queue
    q->front = q->size = 0; // initialize front and size to 0
    q->rear = MAX - 1; // initialize rear to the last index
    q->array = (struct queue_cell*)malloc(MAX * sizeof(struct queue_cell)); // allocate memory for the array of queue cells
    return q; // return the queue
}

// The main function
int main() {
    struct queue* q = init(); // create an empty queue
    int choice; // variable to store the user choice
    while (1) { // loop until the user exits
        display_menu(); // display the main menu
        scanf(" %d", &choice); // read the user choice
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // buffer
        handle_choice(q, choice); // handle the user choice
    }
    return 0;
}

// A function to check if the queue is empty
int empty(struct queue* q) {
    return (q->size == 0); // return true if size is 0, otherwise return false
}

// A function to check if the queue is full
int full(struct queue* q) {
    return (q->size == MAX); // return true if size is MAX, otherwise return false
}

// A function to enqueue an item to the queue
void enqueue(struct queue* q, char* name, char* order) {
    if (full(q)) { // check if the queue is full
        printf("The queue is full. Cannot enqueue.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX; // increment rear index in circular fashion
    strcpy(q->array[q->rear].name, name); // copy the name to the rear cell
    strcpy(q->array[q->rear].order, order); // copy the order to the rear cell
    q->size = q->size + 1; // increment the size of the queue
    printf("Enqueued %s's order of %s.\n", name, order);
}

// A function to dequeue an item from the queue
struct queue_cell dequeue(struct queue* q) {
    struct queue_cell cell; // create a queue cell to store the dequeued item
    if (empty(q)) { // check if the queue is empty
        printf("The queue is empty. Cannot dequeue.\n");
        strcpy(cell.name, "None"); // set the name to "None"
        strcpy(cell.order, "None"); // set the order to "None"
        return cell; // return the cell
    }
    cell = q->array[q->front]; // copy the front cell to the cell
    q->front = (q->front + 1) % MAX; // increment front index in circular fashion
    q->size = q->size - 1; // decrement the size of the queue
    return cell; // return the cell
}

// A function to get the front item of the queue
struct queue_cell front(struct queue* q) {
    struct queue_cell cell; // create a queue cell to store the front item
    if (empty(q)) { // check if the queue is empty
        printf("The queue is empty. No front item.\n");
        strcpy(cell.name, "None"); // set the name to "None"
        strcpy(cell.order, "None"); // set the order to "None"
        return cell; // return the cell
    }
    cell = q->array[q->front]; // copy the front cell to the cell
    return cell; // return the cell
}

// A function to display the main menu
void display_menu() {
    printf("\nMENU:\n");
    printf("[1] Fall in line\n");
    printf("[2] Serve order\n");
    printf("[3] Next order\n");
    printf("[4] Closing time\n");
    printf("[0] Exit\n");
    printf("Enter choice: ");
}

// A function to handle the user choice
void handle_choice(struct queue* q, int choice) {
    char name[LEN], order[LEN]; // variables to store the name and order of the customer
    struct queue_cell cell; // variable to store the queue cell
    switch (choice) {
        case 1: // fall in line
            printf("Enter the name of the person falling in line: ");
            fgets(name, sizeof(name), stdin); // read the name
            name[strcspn(name, "\n")] = 0; // remove newline character
            printf("Enter the order of the person: ");
            fgets(order, sizeof(order), stdin); // read the order
            order[strcspn(order, "\n")] = 0; // remove newline character
            enqueue(q, name, order); // enqueue the name and order to the queue
            break;
        case 2: // serve order
            cell = dequeue(q); // dequeue the front item from the queue
            if (strcmp(cell.name, "None") != 0) { // check if the queue is not empty
                printf("Now serving %s to customer %s.\n", cell.order, cell.name); // display the message
            } else {
                printf("The QUEUE is EMPTY. No orders to serve.\n"); // display the message
            }
            break;
        case 3: // next order
            cell = front(q); // get the front item from the queue
            if (strcmp(cell.name, "None") != 0) { // check if the queue is not empty
                printf("Next order: %s of customer %s.\n", cell.order, cell.name); // display the message
            } else {
                printf("The QUEUE is EMPTY. No order to serve.\n"); // display the message
            }
            break;
        case 4: // closing time
            while (!empty(q)) { // loop until the queue is empty
                cell = dequeue(q); // dequeue the front item from the queue
                printf("Now serving %s to customer %s.\n", cell.order, cell.name); // display the message
            }
            printf("All orders have been served.\n"); // display the message
            break;
        case 0: // exit
            printf("The order system has been terminated.\n"); // display the message
            exit(0); // terminate the program
            break;
        default: // invalid choice
            printf("Incorrect choice. Please try again.\n"); // display the message
            break;
    }
}
