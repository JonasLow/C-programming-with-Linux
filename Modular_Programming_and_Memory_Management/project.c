/* Write a function isReverse() that checks whether a given word is the reverse 
of another given word. More precisely, the function should take as inputs two 
words (null-terminated arrays of characters) and return an integer. If indeed 
the second word is the reverse of the first then the function should return the
integer 1, otherwise it should return a 0.

Your main() function should read two words from the user input (you can assume 
that neither word has more than 99 characters) and then call the function 
isReverse, passing both words to this function. The function should return an 
integer as described above and your main program needs to print out a sentence, 
indicating whether indeed, the first word is the reverse of the second word (see
below examples). */

#include <stdio.h>

int isReverse(char word1[], char word2[]);

int main(void){
    char word1[100];
    char word2[100];
    
    scanf("%s\n", word1);
    scanf("%s\n", word2);
    
    int check = isReverse(word1, word2);
    if (check == 1){
        printf("%s is the reverse of %s\n", word1, word2);
    } else {
        printf("%s is not the reverse of %s\n", word1, word2);
    }
    return 0;
}

int isReverse(char a[], char b[]){
    int i = 0;
    int j = 0;
    int lengthA = 0;
    int lengthB = 0;
    int checker = 1;
    
    while (a[i] != '\0'){
        lengthA++;
        i++;
    }
    while (b[j] != '\0'){
        lengthB++;
        j++;
    }
    
    for (i = 0; i < lengthA; i++){
        if (a[i] != b[lengthB - 1 - i]){
            checker = 0;
        }
    }
    return checker;
}
