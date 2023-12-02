#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int user = 0;
    scanf("%d\n", &user);
    
    FILE *ifile;
    ifile = fopen("myGrades.txt", "r");
    int inside = 0;
    int last[10000];
    int i = 0;
    int j = 0;
    
    for (i = 0; i < 10000; i++) {
        last[i] = 0;
    }
    
    while (fscanf(ifile, "%d", &last[j]) != EOF){
        j++;
    }
    
    
    if (last[j - 1] == user) {
        inside = 1;
    }
    
    i = 0;
    if (!inside) {
        while (last[i] != 0) {
            printf("%d ", *(last + i));
            i++;
        }
        printf("%d", user);
    } else {
        while (last[i] != 0) {
            printf("%d ", *(last + i));
            i++;
        }
    }

    return 0;
}