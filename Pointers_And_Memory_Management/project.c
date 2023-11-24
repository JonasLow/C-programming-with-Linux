#include <stdio.h>
#include <stdlib.h>

int * allocateIntArray(int num);
int ** allocateIntStarArray(int num);
void display(int ** Array, int row, int column);
void freer(int ** ptr, int n);

int main(void){
    int column = 0;
    int row = 0;
    scanf("%d\n", &column);
    scanf("%d\n", &row);
    
    int i = 0;
    int j = 0;
    
    int ** temperature = allocateIntStarArray(row);
    
    for (j = 0; j < row; j++){
        * (temperature + j) = allocateIntArray(column);
        for (i = 0; i < column; i++){
            scanf("%d", &temperature[j][i]);
        }
    }
    
    display(temperature, row, column);
    freearray(temperature, column);
    return 0;
}

int ** allocateIntStarArray(int num){
    int ** ptr = (int **) malloc(num * sizeof(int *));
    return ptr;
}

int * allocateIntArray(int num){
    int * ptr = (int *) malloc(num * sizeof(int));
    return ptr;
}

void display(int ** temperature, int row, int column){
    int i = 0;
    int j = 0;
    for (j = 0; j < row; j++){
        for (i = 0; i < column; i++){
            if (temperature[j][i] > 1000){
                printf("[X]");
            } else if (temperature[j][i] >= 100){
                printf("[*]");
            } else {
                printf("[ ]");
            }
        }
        printf("\n");
    }   
}

void freearray(int ** ptr, int n){
    int j = 0;
    for (j = 0; j < n; j++){
        free(ptr[j]);
    }
    free(ptr);
}