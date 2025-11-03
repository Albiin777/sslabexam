#include <stdio.h>
#include <stdlib.h>   

int main() {
    int n, dsize;
    printf("Enter no. of disk requests: ");
    scanf("%d", &n);
    printf("Enter the disk size: ");
    scanf("%d", &dsize);

    int req[n], head, tseek = 0;

    printf("Enter the request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        if (req[i] > dsize) {
            printf("Request greater than disk size.\n");
            return 1;
        } }

    printf("Enter the current head position: ");
    scanf("%d", &head);

    for (int i = 0; i < n; i++) {
        int seek = abs(head - req[i]);
        printf("Move from %d to %d with seek %d\n", head, req[i], seek);
        tseek += seek;
        head = req[i];
    }

    printf("Total seek time: %d\n", tseek);
    return 0;
}
