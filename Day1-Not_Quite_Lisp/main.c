#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

FILE *entry;

char *encr_path = malloc(128);
char file_name[50];
int current_size = 128;
int delivery_floor = 0;
int size_sequence = 0;

int basement_signal = 0;
int basement_entry = 0;


if ((encr_path) == NULL){
        printf("Error: Memory allocation was not possible\n");
        exit(EXIT_FAILURE);
}


printf("Insert name of the file with the sequence of parenthesis (To exit type 'exit'):");

gets(file_name);

if(!(strcmp(file_name, "exit"))){
    exit(0);
}

if ((entry = fopen(file_name, "r")) == NULL){
    printf("Error: Error while opening the file\n");
    exit(EXIT_FAILURE);
}



if(encr_path != NULL){
    int l = EOF;
    int counter1 = 0;

    while((l = fgetc(entry)) != '\n' && l != EOF){
        encr_path[counter1++] = (char)l;
        size_sequence++;
        if(counter1 == current_size){
            current_size = counter1+128;
            encr_path = realloc(encr_path, current_size);
        }
    }
    encr_path[counter1]= '\0';

}


for(int counter = 0; counter < size_sequence; counter++){
    if(encr_path[counter] == ')'){
    delivery_floor--;
    }else if(encr_path[counter] == '('){
    delivery_floor++;
    }else{
    printf("Invalid character in sequence.\n");
    exit(0);
    }

    if(delivery_floor == -1 && basement_signal == 0){
        basement_entry = counter+1;
        basement_signal++;
    }


}
printf("The floor Santa has to go is: %d\nHe entered the basement at character position: %d\n", delivery_floor, basement_entry);
free(encr_path);
encr_path = NULL;
fclose(entry);
main();
}
