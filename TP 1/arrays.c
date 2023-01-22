#include "arrays.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void print_array(int t[], int size) {
    int i;
    printf("[ ");
    for (i = 0; i < size; i++) {
        printf("%d ", t[i]);
    }
    printf("]\n");
    sleep(2);
}

int *create_array(int max_size) {
    int *ptr = (int*)malloc(max_size*sizeof(int));
    return ptr;
}

void free_array(int t[]) {
    free(t);
}

/*
 * Write this function!
 */
void insert_unsorted(int t[], int *size, int elt) {
    t[*size] = elt;
    (*size)++;
}

/*
 * Write this function!
 */
int find_unsorted(int t[], int size, int elt) {
    int i;
    for (i = 0; i < size; i++) {
        if (t[i] == elt) {
            return 1;
        }
    }
    return 0;
}

/*
 * Write this function!
 */
void insert_sorted(int t[], int *size, int elt) {
    int i;
    for(i = *size; i > 0 && t[i-1] > elt; i--)
        t[i] = t[i-1];
    t[i] = elt;
    (*size)++;
}

/*
 * Write this function!
 */
int find_sorted(int t[], int size, int elt) {
    int lo = 0;
    int max = size - 1;
    int mid;

    while (lo <= max) {
        mid = (lo + max) / 2;
        if (t[mid] == elt) {
            return 1;
        } else if (t[mid] < elt) {
            lo = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return 0;
}