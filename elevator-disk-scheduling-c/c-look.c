#include <stdio.h>
#include <stdlib.h>
#include "algos.h"

int clook(int requests[], int n, int head) {
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

    // go right, no going to disk end
    for (int i = 0; i < r; i++) {
        total_seek += abs(head - right[i]);
        serve(right[i], total_seek);
        head = right[i];
    }

    for (int i = 0; i < l; i++) {
        total_seek += abs(head - left[i]);
        serve(left[i], total_seek);
        head = left[i];
    }

    return total_seek;
}