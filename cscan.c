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

    // Find position of first request greater than head
    int pos = n; 
    for (int p = 0; p < n; p++) {
        if (head < a[p]) {
            pos = p;
            break;
        }
    }

    int temphead = head, seek = 0, tseek = 0;

    printf("\n\nHead Movement Order:\n");

    // -------------------------------
    // C-SCAN logic
    // -------------------------------
    if (dir == 1) { // move right first
        // Serve right side
        for (int i = pos; i < n; i++) {
            seek = abs(temphead - a[i]);
            tseek += seek;
            temphead = a[i];
            printf("%d ", temphead);
        }

        // Go to end of disk, then jump to start
        tseek += abs(size - 1 - temphead);
        temphead = 0;
        tseek += (size - 1); // jump from end to start

        // Serve remaining left side
        for (int i = 0; i < pos; i++) {
            seek = abs(temphead - a[i]);
            tseek += seek;
            temphead = a[i];
            printf("%d ", temphead);
        }

    } else { // move left first
        // Serve left side
        for (int i = pos - 1; i >= 0; i--) {
            seek = abs(temphead - a[i]);
            tseek += seek;
            temphead = a[i];
            printf("%d ", temphead);
        }

        // Go to start of disk, then jump to end
        tseek += abs(temphead - 0);
        temphead = size - 1;
        tseek += (size - 1); // jump from start to end

        // Serve remaining right side
        for (int i = n - 1; i >= pos; i--) {
            seek = abs(temphead - a[i]);
            tseek += seek;
            temphead = a[i];
            printf("%d ", temphead);
        }
    }

    printf("\n\nTOTAL SEEK TIME: %d\n", tseek);
    return 0;
}
