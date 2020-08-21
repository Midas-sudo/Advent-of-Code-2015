#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wrapper_calc (int *box, int total[1]);
int smallest_numb(int one, int two, int three);
void ribon_calc (int *box, int total_rib[1]);

int main()
{
FILE *entry;
char file_name[50];
int **matrix_presents;
int size_matrix = 25;
int a = 0;
int total[1] = {0};
int total_rib[1] = {0};

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

do{
    a++;
    if(a == size_matrix){
        matrix_presents = (int **) realloc(matrix_presents, (size_matrix+25)*sizeof(int *));
        for(int l=0; l<25; l++){
            if ((matrix_presents[size_matrix+l] = (int *) malloc( 3*sizeof(int))) == NULL){
                printf("Error: Memory allocation was not possible (2)\n");
                exit(EXIT_FAILURE);
            }
        }
        size_matrix = size_matrix+25;
    }
}while(fscanf(entry, " %dx%dx%d\n", &matrix_presents[a][0], &matrix_presents[a][1], &matrix_presents[a][2]) != EOF);



for(int l=0; l<a;l++){
    wrapper_calc(matrix_presents[l], total);
    ribon_calc (matrix_presents[l], total_rib);
}





printf("Total of Wrapping: %d\nTotal of Ribon: %d\n", total[0], total_rib[0]);

main();

}


void ribon_calc (int *box, int total_rib[1]){
int perimeter = 0, bigger_side = 0;


bigger_side = box[0] > box[1] ? (box[0] > box[2] ? box[0] : box[2]) : (box[1] > box[2] ? box[1] : box[2]);

perimeter = box[0]+box[1]+box[2]-bigger_side;

total_rib[0] = total_rib[0] + (2*(perimeter)+(box[0]*box[1]*box[2]));

}

void wrapper_calc (int *box, int total[1]){

int side1=0, side2=0, side3=0, extra=0;

side1 = box[0]*box[1];
side2 = box[0]*box[2];
side3 = box[1]*box[2];

extra = smallest_numb(side1, side2, side3);

total[0]= total[0]+(2*(side1+side2+side3)+extra);
}



int smallest_numb(int one, int two, int three){
if(one >= two){
    if(two >= three){
        one = three;
    }else if(two < three){
        one = two;
    }
}else if(one<=two){
    if(one >= three){
        one = three;
    }else if(one < three){
        one = one;
    }
}
return one;
}
