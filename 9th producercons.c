#include <stdio.h>

int buffer[10];
int in = 0, out = 0;
int size;

void producer(int item) {

    if((in + 1) % size == out) {
        printf("Buffer is FULL. Producer cannot produce %d\n", item);
        return;
    }

    buffer[in] = item;
    printf("Produced: %d at position %d\n", item, in);
    in = (in + 1) % size;
}

void consumer() {

    if(in == out) {
        printf("Buffer is EMPTY. Consumer cannot consume\n");
        return;
    }

    int item = buffer[out];
    printf("Consumed: %d from position %d\n", item, out);
    out = (out + 1) % size;
}

int main() {
    int choice, item;

    printf("Enter buffer size (max 10): ");
    scanf("%d", &size);

    while(1) {

        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter item to produce: ");
                scanf("%d", &item);
                producer(item);
                break;

            case 2:
                consumer();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
