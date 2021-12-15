#include "menu.h"

void preenche() {
	system("clear");

	float arq_1[MIL], arq_2[DEZ_MIL], arq_3[1000000], array_search_1[5000], array_search_2[10000], array_search_3[100000];
	char array_1[1000];
	char array_2[10000];
	char array_3[1000000];
	char array_search_primeiro[5000];
	char array_search_segundo[10000];
	char array_search_terceiro[100000];
	FILE *file1, *file2, *file3, *file_search_1, *file_search_2, *file_search_3;
	file1 = fopen("1000.txt","w");
	file2 = fopen("10000.txt", "w");
	file3 = fopen("1000000.txt", "w");
	file_search_1 = fopen("search_5000.txt", "w");
	file_search_2 = fopen("search_10000.txt", "w");
	file_search_3 = fopen("search_100000.txt", "w");


	printf("\nPreenchendo arquivo MIL...\n");
	for(int i=0; i<MIL ; i++){
		arq_1[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	    sprintf(array_1, "%.6f", arq_1[i]);
	    strcat(array_1, "\n");
	    fputs(array_1, file1);
	}

	printf("Preenchendo arquivo DEZ_MIL...\n");
	for(int i=0; i<DEZ_MIL ; i++){
		arq_2[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	    sprintf(array_2, "%.6f", arq_2[i]);
	    strcat(array_2, "\n");
	    fputs(array_2, file2);
	}

	printf("Preenchendo arquivo UM_MILHAO...\n");
	for(int i=0; i<1000000 ; i++){
		arq_3[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	    sprintf(array_3, "%.6f", arq_3[i]);
	    strcat(array_3, "\n");
	    fputs(array_3, file3);
	}

	printf("Preenchendo arquivo search_5000...\n");

		  	for(int i=0; i<5000; i++){
		  		array_search_1[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	            sprintf(array_search_primeiro, "%.6f", array_search_1[i]);
	            strcat(array_search_primeiro, "\n");
	            fputs(array_search_primeiro, file_search_1);
			}

	printf("Preencher arquivo search_10000...\n");


		  	for(int i=0; i<10000; i++){
		  		array_search_2[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	            sprintf(array_search_segundo, "%.6f", array_search_2[i]);
	            strcat(array_search_segundo, "\n");
	            fputs(array_search_segundo, file_search_2);
			}

	printf("Preencher arquivo search_100000...\n");


		  	for(int i=0; i<100000; i++){
		  		array_search_3[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	            sprintf(array_search_terceiro, "%.6f", array_search_3[i]);
	            strcat(array_search_terceiro, "\n");
	            fputs(array_search_terceiro, file_search_3);
			}

	fclose(file1);
	fclose(file2);
	fclose(file3);

	fclose(file_search_1);
	fclose(file_search_2);
	fclose(file_search_3);
}