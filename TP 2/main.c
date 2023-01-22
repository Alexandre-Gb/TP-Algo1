#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

void help() {
	printf("Options:\n");
	printf("    -1               Tests for E1.\n");
	printf("    -2               Tests for E2\n");
	printf("    -3               Tests for E3\n");
	printf("    -4               Tests for E4\n");
	printf("    -5               Tests for E5\n");
	printf("    -6               Tests for E6\n");
    return ;
}

int main(int argc, char* argv[]){
    if (argc == 2 ) {
        if (argv[1][0] == '-'){
            switch (argv[1][1]){
            case 'h':
                help();
                break;
            case '1':
                printf("Running E1 tests.\n");
                test_exo1();
                break;
            case '2':
                printf("Running E2 tests.\n");
                test_exo2();
                break;
            case '3':
                printf("Running E3 tests.\n");
                test_exo3();
                break;
            case '4':
                printf("Running E4 tests.\n");
                test_exo4();
                break;
            case '5':
                printf("Running E5 tests.\n");
                test_exo5();
                break;
            case '6':
                printf("Running E6 tests.\n");
                test_exo6();
                break;
            default:
                printf("The argument specified doesn't exist. Please use argument -h to check all avaible arguments.\n");
                return 1;
            }
            return 0;
        }
        printf("Invalid Argument. Use -h for help.\n");
        return 1;
    }
    printf("An argument is required.\n");
    return 1;
}