#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, temp;
    int dir;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int head, size;
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter size of disk: ");
    scanf("%d", &size);

    int a[n];
    printf("Enter the requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the direction of movement:\n1 for right\n0 for left:\n");
    scanf("%d", &dir);

    // Sort the request array (Bubble Sort)
    for (int p = 1; p < n; p++) {
        for (int c = 0; c < n - p; c++) {
            if (a[c] > a[c + 1]) {
                temp = a[c];
                a[c] = a[c + 1];
                a[c + 1] = temp;
            }
        }
    }

    printf("Sorted Requests: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    // Find the position of the head in sorted order
    int pos = 0;
    for (int p = 0; p < n; p++) {
        if (head < a[p]) {
            pos = p;
            break;
        }
    }

    int temphead = head, seek = 0, tseek = 0;

    printf("\n\nHead Movement Order:\n");

    // SCAN logic (Right or Left)
    if (dir == 1) {
        // Move to the right first
        for (int i = pos; i < n; i++) {
            seek = abs(temphead - a[i]);
            tseek += seek;
            temphead = a[i];
            printf("%d ", temphead);
        }

        // Go to the end of disk
        tseek += abs(size - 1 - temphead);
        temphead = size - 1;

        // Then move left
        for (int i = pos - 1; i >= 0; i--) {
            seek = abs(temphead - a[i]);
            tseek += seek;
            temphead = a[i];
            printf("%d ", temphead);
        }
    } else {
        // Move to the left first
        for (int i = pos - 1; i >= 0; i--) {
            seek = abs(temphead - a[i]);
            tseek += seek;
            temphead = a[i];
            printf("%d ", temphead);
        }

        // Go to start of disk
        tseek += abs(temphead - 0);
        temphead = 0;

        // Then move right
        for (int i = pos; i < n; i++) {
            seek = abs(temphead - a[i]);
            tseek += seek;
            temphead = a[i];
            printf("%d ", temphead);
        }
    }

    printf("\n\nTOTAL SEEK TIME: %d\n", tseek);
    return 0;
}
