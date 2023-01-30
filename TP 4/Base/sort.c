#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int nb_less;
int nb_swap;

int less(int a, int b) {
	nb_less++;
	return a < b;
}

void swap(int *a, int *b) {
	nb_swap++;
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void selection_sort(int t[], int size) {
	int i, j, min;
	for (i = 0; i < size; i++) {
		min = i;
		for (j = i + 1; j < size; j++)
			if (less(t[j], t[min])) 
				min = j;
		if (min != i)
			swap(&t[i], &t[min]);
	}
	return;
}

void insertion_sort(int t[], int size){
	int i, j;
	for (i = 0; i < size; i++)
		for (j = i; j > 0 && less(t[j], t[j - 1]); j--)
			swap(&t[j], &t[j - 1]);

	return;
}

int quicksort_part(int t[],int lo,int hi) {
	int i = lo + 1, j = hi;

	while(1) {
		while(less(t[i], t[lo]) && i < hi)
		    i++;

		while(less(t[lo], t[j]) && j > lo)
            j--;

		if(i >= j)
			break;
			
		swap(&t[i], &t[j]);
		i++;
		j--;
	}
	swap(&t[lo], &t[j]);
	return j;
}

void quick(int t[], int lo, int hi) {
	int mid;
	if (lo < hi) {
		mid = quicksort_part(t, lo, hi);
		quick(t, lo, mid - 1);
		quick(t, mid + 1, hi);
	}
}


void quick_sort(int t[], int size)	{
	if (size < 2) 
		return;

	quick(t, 0, size-1);
}