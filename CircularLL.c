
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    printf("%d deleted\n", temp->data);
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    while (front != NULL)
                        dequeue();
                    return 1;
                }
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                while (front != NULL)
                    dequeue();
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    while (front != NULL)
        dequeue();

    return 0;
}
