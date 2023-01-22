#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Exo 1 */
/* 1 */
int palindrome_rec(char str[], int lo, int hi){
    if (lo == hi || hi - lo == 1) 
        return 1;

    if (str[lo] != str[hi]) 
        return 0;

    if (lo < hi + 1) 
        return palindrome_rec(str, lo + 1, hi - 1);

    return 1;
}

/* 2 */
int palindrome(char str[]){
    int i = 0;
    while (str[i] != '\0') 
        i++;
    return palindrome_rec(str, 0, i - 1);
}


/* Exo 2 */
/* 1 */
void increasing_sequence_rec(int n){
	if(n <= 0){
        printf("\n");
        return;
    } 
	increasing_sequence_rec(n-1);
	printf("%d ", n);
}

/* 2 */
void decreasing_sequence_rec(int n){
    if (n == 0){
        printf("\n");
        return;
    }
    printf("%d ", n);
    decreasing_sequence_rec(--n);
}


/* Exo 3 */
/* 1 */
int count(int t[], int lo, int hi, int elt){
	if(lo > hi) 
        return 0;
	if(t[lo] == elt) {
		return count(t, lo+1, hi, elt)+1;
	} else {
		return count(t, lo+1, hi, elt);
	}
}

/* 2 */
int max_count(int t[], int lo, int hi){
	if (lo >= hi) 
        return 0;

	if(count(t, lo, hi, t[lo]) < count(t, lo, hi, t[lo+1]))
		return max_count(t, lo+1, hi);
	else
		return count(t, lo, hi, t[lo]);
		
	return 0;
}


/* Exo 4 */
/* 1 */
int sum_digits_iter(int n) {
	int res = 0;
	int i;
	for(i = 0; n != 0; i++) {
		res += n % 10;
		n = n / 10;
	}
	return res;
}

/* 2 */
int sum_digits_rec(int n) {
	if(n == 0) 
        return 0;
    return (n % 10 + sum_digits_rec(n / 10));
}


/* Exo 5 */
/* 2 */
int digit_sum_digits_rec(int n){
	if(n < 10) 
        return n;
    return (digit_sum_digits_rec((n / 10) + (n % 10)));
}


/* Exo 6 */
/* 1 */
int longest_incr_iter(int t[], int lo, int hi){
    int res = 1;
	int len = 1;

	int i;
	for (i = lo + 1; i <= hi; i++) {
		if (t[i] > t[i-1])
            len++;
		else {
			if (res < len)
                res = len;
			len = 1;
		}
	}
	if (res < len) 
        res = len;
	return res;
}

/* 2 */
/* Je ne vois pas comment résoudre le problème via une fonction récursive, sans ajouter de paramètres */
int first_incr(int t[], int lo, int hi){
	int lenght = 1;

	int i;
	for (i = lo + 1; i <= hi; i++) {
		if (t[i] > t[i-1]) 
            lenght++;
		else 
            break;
	}
	return lenght;
}

/* 3 */
int longest_incr_rec(int t[], int lo, int hi){
    int size = first_incr(t, lo, hi);
	if (first_incr(t, lo, hi) < size || lo == 0)
		return size;
	else
		return longest_incr_rec(t, lo - 1, hi);
}