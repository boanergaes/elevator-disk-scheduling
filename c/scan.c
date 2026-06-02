#include <stdio.h>
#include  <stdlib.h>
#include "algos.h"

int scan(int requests[], int n, int head, int disk_size) {
    int total_seek = 0;
    int i, pos;

    sort(requests, n);

    int left[MAX], right[MAX];
    int l = 0, r = 0;

    for (i = 0; i < n; i++) {
        if (requests[i] < head)
            left[l++] = requests[i];
        else
            right[r++] = requests[i];
    }

    // go right first
    for (i = 0; i < r; i++) {
        total_seek += abs(head - right[i]);
        serve(right[i], total_seek);
        head = right[i];
    }

    // go to end
    total_seek += abs(head - (disk_size - 1));
    head = disk_size - 1;

    // go left
    for (i = l - 1; i >= 0; i--) {
        total_seek += abs(head - left[i]);
        serve(left[i], total_seek);
        head = left[i];
    }

    return total_seek;
}