#include <stdio.h>

int main(void){
    char word[101];
    int length = 0;
    int midlength = 0;
    int i = 0;
    int j = 0;
    int check = 0;
    
    scanf("%s", word);
    while (word[i] != '\0'){
        length++;
        i++;
    }
    midlength = length / 2;
    
    for (j = 0; j < length; j++){
        if ((word[j] == 't' || word[j] == 'T') && j <= midlength){
            printf("1");
            check = 1;
        }  else if ((word[j] == 't' || word[j] == 'T') && j > midlength){
            printf("2");
            check = 1;
        } else if (check != 1 && j == length - 1){
            printf("-1");
        }
    } 
    
    return 0;
}