#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generators.list.c"
#include "algorythms.list.c"


// FUNKCJA TESTUJĄCA
int main(int argc, char **argv){
	int algorythm, dataType, quantity;
	int *table;
		
	sscanf(argv[1], "%d", &algorythm);
	sscanf(argv[2], "%d", &dataType);
	sscanf(argv[3], "%d", &quantity);

	//printf("%d\t%d\t%d\t", algorythm, dataType, quantity);
	
	table = malloc((quantity+1) * sizeof(int));
	
	switch(dataType){
		case 1:
			data_sorted(table, quantity);
			break;
		case 2:
			data_reverse(table, quantity);
			break;
		case 3:
			data_exceptions(table, quantity);
			break;
		default:
			data_random(table, quantity);
	}
	
	clock_t start, 
			stop;
	
	switch(algorythm){
		case 1:
			start = clock();
			coctail_sort(table, quantity);
			stop = clock();
			break;
		case 2:
			start = clock();
			selection_sort(table, quantity);
			stop = clock();
			break;
		case 3:
			start = clock();
			insertion_sort(table, quantity);
			stop = clock();
			break;
		case 4:
			start = clock();
			quick_sort(table, 0, quantity);
			stop = clock();
			break;
		case 5:
			start = clock();
			heap_sort(table, quantity);
			stop = clock();
			break;
		case 6:
			start = clock();
			shell_sort(table, quantity);
			stop = clock();
			break;
	}
	free(table);
	printf("%lf", (double) (stop-start)/CLOCKS_PER_SEC );
	
	return 0;
}











