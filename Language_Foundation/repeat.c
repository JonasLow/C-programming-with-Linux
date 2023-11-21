#include <stdio.h>

int main(void){
    char word[51];
    int length = 0;
    int i = 0;
    int j = 0;
    
    scanf("%s", word);
    
    while (word[i] != '\0'){
        length++;
        i++;
    }
    
    int counter[length];
    for (i = 0; i < length; i++){
        counter[i] = 0;
    }
    
    for (i = 0; i < length; i++){
        for (j = i + 1; j < length; j++){
            if (word[i] == word[j] && counter[i] > -1){
                counter[i] = 1;
                counter[j] = -1;
            }
        }
    }
    
    int repeat = 0;
    for (i = 0; i < length; i++){
        if (counter[i] == 1){
            repeat++;
        }
    }
    
    printf("%d", repeat);
    
    return 0;
}