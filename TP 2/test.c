#include <stdio.h>
#include <stdlib.h>

#include "exo.h"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KWHT  "\x1B[37m"

void print_array(int t[], int size){
	int i;
	printf("[");
	for(i = 0; i <= size; i++) {
		if(i != 0) printf(" ");
		printf("%d", t[i]);
		if(i != size) printf(","); 

	}
	printf("]");
	return;
}

void print_results(int total, int success, char *exo){
	printf("Success rate for %s : ", exo);
	if (total == success) {
		printf("%s%d/%d\n", KGRN, success, total);
	} else {
		printf("%s%d/%d\n", KRED, success, total);
	}
	printf("%s", KWHT);
	return;
}


/* EXO 1 */
int p_test_palindrome(int count, int max, char* word, int expectation){
	printf("\nTEST %d/%d: ", count, max);
	int result = palindrome(word);

	printf("palindrome(%s);\n", word);
	printf("expectation: %d | result: %d\n", expectation, result);
	if(result == expectation) {
		printf("  %sSUCCESS!%s\n", KGRN, KWHT);
		return 1;
	} else {
		printf("  %sFAILURE!%s\n", KRED, KWHT);
		return 0;
	}
}

int test_palindrome(){
	int max = 5;
	int success = 0;
	int count = 0;
	printf("\nTEST: PALINDROME----\n");
	printf("Number of tests: %d\n", max);

	count++;
	success += p_test_palindrome(count, max, "kayak", 1);

	count++;
	success += p_test_palindrome(count, max, "bonjour", 0);

	count++;
	success += p_test_palindrome(count, max, "", 1);
		
	count++;
	success += p_test_palindrome(count, max, "kayaK", 0);
		
	count++;
	success += p_test_palindrome(count, max, "a", 1);

	print_results(max, success, "Tests Palindrome");
	return (success == max);
}



/* EXO 2 */
void p_test_increase_seq(int count, int max, int n){
	printf("\nTEST %d/%d: ", count, max);

	printf("increase_seq(%d);", n);
	increasing_sequence_rec(n);
	printf("\n");
	return;
}

void p_test_decrease_seq(int count, int max, int n){
	printf("\nTEST %d/%d: ", count, max);

	printf("decrease_seq(%d);\n", n);
	decreasing_sequence_rec(n);
	return;
}

void test_increase_seq() {
	int success = 0;
	int count = 0;
	int max = 3;
	printf("\nTEST: INCREASE SEQUENCE----\n");
	printf("Number of tests: %d\n", max);

	count++;
	p_test_increase_seq(count, max, 12);
	success++;

	count++;
	p_test_increase_seq(count, max, 5);
	success++;

	count++;
	p_test_increase_seq(count, max, 0);
	success++;


	print_results(max, success, "Tests Increase Sequence");
	return;
}

void test_decrease_seq() {
	int success = 0;
	int count = 0;
	int max = 3;
	printf("\nTEST: DECREASE SEQUENCE----\n");
	printf("Number of tests: %d\n", max);

	count++;
	p_test_decrease_seq(count, max, 12);
	success++;

	count++;
	p_test_decrease_seq(count, max, 5);
	success++;

	count++;
	p_test_decrease_seq(count, max, 0);
	success++;

	print_results(max, success, "Tests Decrease Sequence");
	return;
}


/* EXO 3 */
int p_test_count(int c, int max, int t[], int lo, int hi, int elt, int expectation){
	printf("\nTEST %d/%d: ", c, max);
	int result = count(t, lo, hi, elt);

	printf("count(");
	print_array(t, hi);
	printf(", %d, %d, %d);\n", lo, hi, elt);
	printf("expectation: %d | result: %d\n", expectation, result);
	if(result == expectation) {
		printf("  %sSUCCESS!%s\n", KGRN, KWHT);
		return 1;
	} else {
		printf("  %sFAILURE!%s\n", KRED, KWHT);
		return 0;
	}
}

int p_test_max_count(int count, int max, int t[], int lo, int hi, int expectation){
	printf("\nTEST %d/%d: ", count, max);
	int result = max_count(t, lo, hi);

	printf("count(");
	print_array(t, hi);
	printf(", %d, %d);\n", lo, hi);
	printf("expectation: %d | result: %d\n", expectation, result);
	if(result == expectation) {
		printf("  %sSUCCESS!%s\n", KGRN, KWHT);
		return 1;
	} else {
		printf("  %sFAILURE!%s\n", KRED, KWHT);
		return 0;
	}
}

void test_count(){
	int success = 0;
	int count = 0;
	int max = 3;
	printf("\nTEST: COUNT----\n");
	printf("Number of tests: %d\n", max);

	int t1[] = {1, 4, 3, 3, 2, 3, 3, 4};
	int t2[] = {1, 2, 3, 3, 4, 5, 5};

	count++;
	success += p_test_count(count, max, t1, 0, 7, 3, 4);

	count++;
	success += p_test_count(count, max, t2, 0, 6, 2, 1);

	count++;
	success += p_test_count(count, max, t2, 0, 6, 5, 2);
	
	print_results(max, success, "Tests Count");
	return;
}

void test_max_count(){
	int success = 0;
	int count = 0;
	int max = 3;
	printf("\nTEST: MAX COUNT----\n");
	printf("Number of tests: %d\n", max);

	int t1[] = {1, 4, 3, 3, 2, 3, 3, 4};
	int t2[] = {1, 2, 1, 2, 2, 1, 3, 3, 4};
	int t3[] = {1, 1, 1, 1, 1, 1, 1, 2, 1};

	count++;
	success += p_test_max_count(count, max, t1, 0, 7, 4);

	count++;
	success += p_test_max_count(count, max, t2, 0, 8, 3);

	count++;
	success += p_test_max_count(count, max, t3, 0, 8, 8);

	print_results(max, success, "Tests Max Count");
	return;
}


/* EXO 4 */
int p_test_sum_digits_iter(int c, int max, int n, int expectation){
	printf("\nTEST %d/%d: ", c, max);
	int result = sum_digits_iter(n);

	printf("sum_digits_iter(%d);\n", n);
	printf("expectation: %d | result: %d\n", expectation, result);
	if(result == expectation) {
		printf("  %sSUCCESS!%s\n", KGRN, KWHT);
		return 1;
	} else {
		printf("  %sFAILURE!%s\n", KRED, KWHT);
		return 0;
	}
}

int p_test_sum_digits_rec(int c, int max, int n, int expectation){
	printf("\nTEST %d/%d: ", c, max);
	int result = sum_digits_rec(n);

	printf("sum_digits_iter(%d);\n", n);
	printf("expectation: %d | result: %d\n", expectation, result);
	if(result == expectation) {
		printf("  %sSUCCESS!%s\n", KGRN, KWHT);
		return 1;
	} else {
		printf("  %sFAILURE!%s\n", KRED, KWHT);
		return 0;
	}
}

void test_sum_digits_iter(){
	int success = 0;
	int count = 0;
	int max = 5;
	printf("\nTEST: SUM DIGITS (ITER)----\n");
	printf("Number of tests: %d\n", max);

	count++;
	success += p_test_sum_digits_iter(count, max, 123, 6);

	count++;
	success += p_test_sum_digits_iter(count, max, 12345, 15);
	
	count++;
	success += p_test_sum_digits_iter(count, max, 0, 0);

	count++;
	success += p_test_sum_digits_iter(count, max, 1, 1);
	
	count++;
	success += p_test_sum_digits_iter(count, max, 111111111, 9);

	print_results(max, success, "Tests Sum Digits (Iter)");
	return;
}

void test_sum_digits_rec(){
	int success = 0;
	int count = 0;
	int max = 5;
	printf("\nTEST: SUM DIGITS (REC)----\n");
	printf("Number of tests: %d\n", max);

	count++;
	success += p_test_sum_digits_iter(count, max, 123, 6);

	count++;
	success += p_test_sum_digits_iter(count, max, 12345, 15);
	
	count++;
	success += p_test_sum_digits_iter(count, max, 0, 0);

	count++;
	success += p_test_sum_digits_iter(count, max, 1, 1);
	
	count++;
	success += p_test_sum_digits_iter(count, max, 111111111, 9);

	print_results(max, success, "Tests Sum Digits (Rec)");
	return;
}


/* EXO 5 */
int p_test_digit_sum_digits_rec(int c, int max, int n, int expectation){
	printf("\nTEST %d/%d: ", c, max);
	int result = digit_sum_digits_rec(n);

	printf("digit_sum_digits_rec(%d);\n", n);
	printf("expectation: %d | result: %d\n", expectation, result);
	if(result == expectation) {
		printf("  %sSUCCESS!%s\n", KGRN, KWHT);
		return 1;
	} else {
		printf("  %sFAILURE!%s\n", KRED, KWHT);
		return 0;
	}
}

void test_digit_sum_digits_rec(){
	int success = 0;
	int count = 0;
	int max = 5;
	printf("\nTEST: DIGIT SUM DIGITS (REC)----\n");
	printf("Number of tests: %d\n", max);
	
	count++;
	success += p_test_digit_sum_digits_rec(count, max, 123, 6);

	count++;
	success += p_test_digit_sum_digits_rec(count, max, 12345, 6);
	
	count++;
	success += p_test_digit_sum_digits_rec(count, max, 0, 0);

	count++;
	success += p_test_digit_sum_digits_rec(count, max, 1, 1);
	
	count++;
	success += p_test_digit_sum_digits_rec(count, max, 99992, 2);

	print_results(max, success, "Tests Digits Sum Digits (Rec)");
	return;
}


/* EXO 6 */
int p_test_longest_incr_iter(int c, int max, int t[], int lo, int hi, int expectation){
	printf("\nTEST %d/%d: ", c, max);
	int result = longest_incr_iter(t, lo, hi);

	printf("longest_incr_iter(");
	print_array(t, hi);
	printf(", %d, %d);\n", lo, hi);
	printf("expectation: %d | result: %d\n", expectation, result);
	if(result == expectation) {
		printf("  %sSUCCESS!%s\n", KGRN, KWHT);
		return 1;
	} else {
		printf("  %sFAILURE!%s\n", KRED, KWHT);
		return 0;
	}
}

void test_longest_incr_iter(){
	int success = 0;
	int count = 0;
	int max = 4;
	printf("\nTEST: LONGEST INCR (ITER)----\n");
	printf("Number of tests: %d\n", max);
	
	int t1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int t2[] = {1, 1, 1, 1, 1};
	int t3[] = {1, 8, 9};
	int t4[] = {1, 8, 2, 9};

	count++;
	success += p_test_longest_incr_iter(count, max, t1, 0, 7, 8);

	count++;
	success += p_test_longest_incr_iter(count, max, t2, 0, 4, 1);
	
	count++;
	success += p_test_longest_incr_iter(count, max, t3, 0, 2, 3);

	count++;
	success += p_test_longest_incr_iter(count, max, t4, 0, 3, 2);

	print_results(max, success, "Tests Longest Incr (Iter)");
	return;
}

int p_test_first_incr(int c, int max, int t[], int lo, int hi, int expectation){
	printf("\nTEST %d/%d: ", c, max);
	int result = first_incr(t, lo, hi);

	printf("first_incr(");
	print_array(t, hi);
	printf(", %d, %d);\n", lo, hi);
	printf("expectation: %d | result: %d\n", expectation, result);
	if(result == expectation) {
		printf("  %sSUCCESS!%s\n", KGRN, KWHT);
		return 1;
	} else {
		printf("  %sFAILURE!%s\n", KRED, KWHT);
		return 0;
	}
}

void test_first_incr(){
	int success = 0;
	int count = 0;
	int max = 5;
	printf("\nTEST: FIRST INCR----\n");
	printf("Number of tests: %d\n", max);
	
	int t1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int t2[] = {1, 1, 1, 1, 1};
	int t3[] = {1, 8, 2, 1};

	count++;
	success += p_test_first_incr(count, max, t1, 0, 7, 8);

	count++;
	success += p_test_first_incr(count, max, t2, 0, 4, 1);
	
	count++;
	success += p_test_first_incr(count, max, t2, 2, 4, 1);

	count++;
	success += p_test_first_incr(count, max, t3, 0, 3, 2);

	count++;
	success += p_test_first_incr(count, max, t3, 1, 3, 1);

	print_results(max, success, "Tests First Incr");
	return;
}

int p_test_longest_incr_rec(int c, int max, int t[], int lo, int hi, int expectation){
	printf("\nTEST %d/%d: ", c, max);
	int result = longest_incr_rec(t, lo, hi);

	printf("longest_incr_rec(");
	print_array(t, hi);
	printf(", %d, %d);\n", lo, hi);
	printf("expectation: %d | result: %d\n", expectation, result);
	if(result == expectation) {
		printf("  %sSUCCESS!%s\n", KGRN, KWHT);
		return 1;
	} else {
		printf("  %sFAILURE!%s\n", KRED, KWHT);
		return 0;
	}
}

void test_longest_incr_rec(){
	int success = 0;
	int count = 0;
	int max = 4;
	printf("\nTEST: LONGEST INCR (REC)----\n");
	printf("Number of tests: %d\n", max);
	
	int t1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int t2[] = {1, 1, 1, 1, 1};
	int t3[] = {1, 8, 9};
	int t4[] = {1, 8, 2, 9};

	count++;
	success += p_test_longest_incr_rec(count, max, t1, 0, 7, 8);

	count++;
	success += p_test_longest_incr_rec(count, max, t2, 0, 4, 1);
	
	count++;
	success += p_test_longest_incr_rec(count, max, t3, 0, 2, 3);

	count++;
	success += p_test_longest_incr_rec(count, max, t4, 0, 3, 2);

	print_results(max, success, "Tests Longest Incr (Rec)");
	return;
}



void test_exo1(){
	test_palindrome();
};

void test_exo2(){
	test_increase_seq();
	test_decrease_seq();
};

void test_exo3(){
	test_count();
	test_max_count();
};

void test_exo4(){
	test_sum_digits_iter();
	test_sum_digits_rec();
};

void test_exo5(){
	test_digit_sum_digits_rec();
};

void test_exo6(){
	test_longest_incr_iter();
	test_first_incr();
	test_longest_incr_rec();
};