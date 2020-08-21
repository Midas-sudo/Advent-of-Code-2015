#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wrapper_calc (int box[3], int* total);

int main()
{
FILE *entry;
char file_name[50];
int **matrix_presents;
int size_matrix = 25;
int a = 0;
int* total;

printf("Insert name of the file with the present dimensions (To exit type 'exit'):");

gets(file_name);

printf("Processing...");

if(!(strcmp(file_name, "exit"))){
    exit(0);
}

if ((entry = fopen(file_name, "r")) == NULL){
    printf("Error: Error while opening the file\n");
    exit(EXIT_FAILURE);
}


if ((matrix_presents = (int **) malloc(25*sizeof(int *))) == NULL){
    printf("Error: Memory allocation was not possible (1)\n");
    exit(EXIT_FAILURE);
}
for(int l=0; l<25; l++){
    if ((matrix_presents[l] = (int *) malloc(3*sizeof(int))) == NULL){
        printf("Error: Memory allocation was not possible (2)\n");
        exit(EXIT_FAILURE);
    }
}


fscanf(entry, " %dx%dx%d\n", &matrix_presents[0][0], &matrix_presents[0][1], &matrix_presents[0][2]);

/*do{
    a++;
    if(a == size_matrix){
        matrix_presents = (int **) realloc(matrix_presents, (size_matrix+25)*sizeof(int *));
        size_matrix = size_matrix + 25;
        for(int l=0; l<size_matrix; l++){
            if ((matrix_presents[l] = (int *) realloc(matrix_presents[l], 3*sizeof(int))) == NULL){
                printf("Error: Memory allocation was not possible (2)\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}while(fscanf(entry, " %dx%dx%d\n", &matrix_presents[a][0], &matrix_presents[a][1], &matrix_presents[0][2]) != EOF);
*/
*total = 0;

for(int l=0; l<a;l++){
    wrapper_calc(matrix_presents[a], total);
}










}


void wrapper_calc (int box[3], int* total){


printf("%d %d %d", box[0],box[1],box[2]);
printf(" %d", total);



}
