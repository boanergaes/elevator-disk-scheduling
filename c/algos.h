#ifndef DISK_H
#define DISK_H

#define MAX 100

int scan(int requests[], int n, int head, int disk_size);
int cscan(int requests[], int n, int head, int disk_size);
int clook(int requests[], int n, int head);

void sort(int arr[], int n);
void serve(int request, int curr_seektime);

#endif