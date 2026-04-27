#include <stdio.h>
#include <unistd.h>     // for fork(), sleep()
#include <sys/types.h>  // for pid_t
#include <sys/wait.h>   // for wait()

// Bubble Sort (Parent)
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort (Child)
void selectionSort(int arr[], int n) {
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int arr[20], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();   // create child process

    if(pid > 0) {
        //Parent Process
        printf("\nParent Process (PID: %d)\n", getpid());

        bubbleSort(arr, n);

        printf("Parent sorted array (Bubble Sort): ");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // WAIT → prevents zombie
        wait(NULL);

        printf("Parent: Child process finished.\n");
    }
    else if(pid == 0) {
        //  Child Process
        printf("\nChild Process (PID: %d, Parent PID: %d)\n", getpid(), getppid());

        selectionSort(arr, n);

        printf("Child sorted array (Selection Sort): ");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Zombie demonstration (comment wait in parent to see zombie)
        // Child exits quickly
    }
    else {
        printf("Fork failed!\n");
    }

    return 0;
}
