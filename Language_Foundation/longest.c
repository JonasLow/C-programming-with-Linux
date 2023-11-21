#include <stdio.h>

int main(void){
    int count = 0;
    scanf("%d\n", &count);
    
    char word[101];
    int length[count];
    int lengthcount[101]; 
    int i = 0;
    for (i = 0; i < count; i++){
        length[i] = 0;
    }
    
    int j = 0;
    for (i = 0; i < count; i++){
        scanf("%s", word);
        while (word[j] != '\0'){
            length[i] = j + 1;
            j++;
        }
        lengthcount[length[i]]++;
    }
    
    int biggest = 0;
    for (i = 0; i < count; i++){
        if (length[i] > biggest){
            biggest = length[i];
        } 
    }
    
    printf("%d", biggest);
    
    return 0;
}