/* Your program should first read an integer number indicating how many tracking
codes you plan on entering. Next, for each successive tracking code your program
should read in the integer length of code followed by a space and then the type
of code ('i' for integer, 'd' for decimal, or 'c' for character). Finally your 
program should print the total amount of space required to store all of the
tracking codes (in bytes). If the user enters an incorrect type for any tracking
number, the program should print 'Invalid tracking code type' and exit. */

#include <stdio.h>

int mem(int count, int *, char *);

int main(void){
    int count = 0;
    scanf("%d\n", &count);
    
    int size[count];
    char unit[count];
    int j = 0;
    for (j = 0; j < count; j++){
        scanf("%d %c\n", &size[j], &unit[j]);
    }
    
    int storage = mem(count, size, unit);
    
    if (storage == 0){
        printf("Invalid tracking code type");
    } else {
        printf("%d bytes", storage);
    }
    return 0;
}

int mem(int c, int * size, char * unit){
    int total = 0; 
    int i = 0;
    for (i = 0; i < c; i++){
        if (*(unit + i) == 'i'){
            total = total + (*(size + i) * 4);
        } else if (*(unit + i) == 'd'){
            total = total + (*(size + i) * 8);
        } else if (*(unit + i) == 'c'){
            total = total + *(size + i);
        } else {
            total = 0;
            break;
        }
    }
    return total;
}