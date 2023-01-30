#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array.h"
#include "sort.h"

#define MAX_VALUE 10000
#define TEST_SIZE 1000

/*
#define MAX_SIZE 0
#define MAX_SIZE 1000
*/

void generateRandomArray(int n, int *arr) {
    int i, j;
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }
    for (i = 0; i < n; i++) {
        j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int values[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

int compare(const void *a, const void *b){
	int aint = *(int *)a;
	int bint = *(int *)b;
	if (aint == bint)
		return 0;
	else if (aint < bint)
		return -1;
	else
		return 1;
}


int main(){
	srand(time(NULL));

	int* tab = NULL;

	tab = create_array(TEST_SIZE);
    fill_random_array(tab, TEST_SIZE, MAX_VALUE);

	int i;
	for (i = 0; i < TEST_SIZE; i++)
		printf("%d ", tab[i]);
	printf("\n--------\n");

	free(tab);
	return EXIT_SUCCESS;
}
