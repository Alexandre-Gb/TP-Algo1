#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array.h"
#include "sort.h"

#define MAX_VALUE 100
#define TEST_SIZE 10000

extern int nb_less;
extern int nb_swap;

int main(int argc, char *argv[]){
    srand(time(NULL));
    nb_less = 0;
    nb_swap = 0;
    int select_nb_less = 0;
    int insert_nb_less = 0;
    int quick_nb_less = 0;

    int select_nb_swap = 0;
    int quick_nb_swap = 0;
    int insert_nb_swap = 0;

    int *tab = NULL;
    int *tab2 = NULL;
    int *tab3 = NULL;
    int *tab4 = NULL;

    FILE *file;

    int max = 100;
    int increment = 10;
    
    /*
     * Test de temps manuel
     */
    if (argc == 2){
        int size = atoi(argv[1]);
        tab = create_array(size);
        fill_random_array(tab, size, MAX_VALUE);

        quick_sort(tab, size);
        printf("Selection sort: %d less, %d swap\n", nb_less, nb_swap);
        free(tab);
    } else {
        file = fopen("sort.dat", "w");

        /*
         * Tris de 0 à 10000 de taille
         * On ajoute 100 à chaque fois
         */
        int i;
        for (i = 0; i <= max; i += increment){
            /*
             * On crée 3 tableaux de taille i
             * On remplit le premier tableau de manière aléatoire
             * On copie le premier tableau dans les trois autres
             * Le premier tableau ne sera pas trié, il sert juste de référence au cas ou l'on souhaite
             * comparer les résultats des tris au tableau original
             */
            tab = create_array(i);
            tab2 = create_array(i);
            tab3 = create_array(i);
            tab4 = create_array(i);
            fill_random_array(tab, i, MAX_VALUE);
            copy_array(tab, tab2, i);
            copy_array(tab, tab3, i);
            copy_array(tab, tab4, i);

            /*
             * Tri par sélection
             */
            selection_sort(tab2, i);
            select_nb_less = nb_less;
            select_nb_swap = nb_swap;

            /*
             * Tri par insertion
             */
            nb_less = 0;
            nb_swap = 0;
            insertion_sort(tab3, i);
            insert_nb_less = nb_less;
            insert_nb_swap = nb_swap;

            /*
             * Tri Quicksort
             */
            nb_less = 0;
            nb_swap = 0;
            quick_sort(tab4, i);
            quick_nb_less = nb_less;
            quick_nb_swap = nb_swap;

            /*
             * On insère les valeurs dans le fichier ".dat":
             * Taille, comparaisons Selection, comparaisons Insertion, comparaisons Quicksort
             */
            fprintf(file, "%d %d %d %d\n", i, select_nb_swap, insert_nb_swap, quick_nb_swap);
            printf("\nPour un tableau de taille %d\n- Tri par Sélection: %d Cmp. | %d Swap.\n- Tri par Insertion: %d Cmp. | %d Swap.\n- Tri Quicksort: %d Cmp. | %d Swap.\n", i, select_nb_less, select_nb_swap, insert_nb_less, insert_nb_swap, quick_nb_less, quick_nb_swap);

            /*
             * On libère la mémoire
             */
            free(tab);
            free(tab2);
            free(tab3);
            free(tab4);
        }
        
        fclose(file);
    }

    /*
     * On ferme le fichier, car on a fini d'y insérer des valeurs.
     */
    return EXIT_SUCCESS;
}