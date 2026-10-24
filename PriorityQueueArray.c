
#include <stdio.h>

#define MAX 100

struct Element {
    int data;
    int priority;
};

struct Element pq[MAX];
int size = 0;

void enqueue(int value, int priority) {
    if (size == MAX) {
        printf("Priority queue is full!\n");
        return;
    }

    int i = size;

    while (i > 0 && pq[i - 1].priority > priority) {
        pq[i] = pq[i - 1];
        i--;
    }

    pq[i].data = value;
    pq[i].priority = priority;
    size++;

    printf("Element inserted successfully.\n");
}

void dequeue() {
    if (size == 0) {
        printf("Priority queue is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", pq[0].data);

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

void display() {
    if (size == 0) {
        printf("Priority queue is empty!\n");
        return;
    }

    printf("\nData\tPriority\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    int choice, value, priority;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            return 0;

        switch (choice) {
            case 1:
                printf("Enter data: ");
                if (scanf("%d", &value) != 1)
                    return 0;

                printf("Enter priority (smaller = higher): ");
                if (scanf("%d", &priority) != 1)
                    return 0;

                enqueue(value, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
