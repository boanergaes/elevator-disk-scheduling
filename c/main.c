#include <stdio.h>
#include "algos.h"

int main() {
    printf("=== Elevator Disk Scheduling Algorithm. ===\n");
    
    int n, head, disk_size;
    int requests[MAX];

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Enter %dth request: ", i+1);
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Requests: ");
    for (int i = 0; i < n; i++)
        printf("%d, ", requests[i]);
    printf("\n");

    printf("\nScheduling...\n");

    printf("\n--- SCAN ---\n");
    int scan_res = scan(requests, n, head, disk_size);

    printf("\n--- C-SCAN ---\n");
    int cscan_res = cscan(requests, n, head, disk_size);
    
    printf("\n--- C-LOOK ---\n");
    int clook_res = clook(requests, n, head);

    printf("\nResults:\n");
    printf("SCAN Total Seek: %d\n", scan_res);
    printf("C-SCAN Total Seek: %d\n", cscan_res);
    printf("C-LOOK Total Seek: %d\n", clook_res);
}