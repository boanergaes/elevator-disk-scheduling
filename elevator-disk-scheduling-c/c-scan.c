#include <stdio.h>
#include <stdlib.h>
#include  "algos.h"

int cscan(int requests[], int n, int head, int disk_size) {
    int total_seek = 0;

    sort(requests, n);

    int right[MAX], left[MAX];
    int r = 0, l = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] >= head)
            right[r++] = requests[i];
        else
            left[l++] = requests[i];
    }

    // go right first
    for (int i = 0; i < r; i++) {
        total_seek += abs(head - right[i]);
        serve(right[i], total_seek);
        head = right[i];
    }

    // go to end
    total_seek += abs(head - (disk_size - 1));
    // jump back to beginning
    total_seek += disk_size - 1;
    head = 0;

    // go  right from start
    for (int i = 0; i < l; i++) {
        total_seek += abs(head - left[i]);
        serve(left[i], total_seek);
        head = left[i];
    }

    return total_seek;
}