/* You'll be given the following inputs: first the number of students, then all 
of the students' final scores, then finally, all of the students' names. Be sure
to look at the example below.

Your output should be one line per student, with each line displaying the 
student's name followed by "rank is" followed by the student's rank.

The order in which names are displayed in the output should be the same as the 
order given in the input. The ranking starts at 1 (meaning this student has the 
highest score), 2 for the second highest grade etc...

Note that no name has more than 50 characters and there are no more than 30 
students. */

#include <stdio.h>

int main(void){
    int studentcount = 0;
    scanf("%d", &studentcount);
    
    int j = 0;
    int score[studentcount];
    int uscore[studentcount];
    for (j = 0; j < studentcount; j++){
        scanf("%d\n", &uscore[j]);
        score[j] = uscore[j];
    }
    
    
    char name[studentcount][51];
    for (j = 0; j < studentcount; j++){
        scanf("%s\n", name[j]);
    }
    
    int i = 0;
    int swapS = 0;
    for (i = 0; i < studentcount - 1; i++){
        for (j = 0; j < studentcount - 1; j++){
            if (score[j] < score[j + 1]){
                swapS = score[j];
                score[j] = score[j + 1];
                score[j + 1] = swapS;
            }
        }
    }
    
    for (i = 0; i < studentcount; i++){
        for (j = 0; j < studentcount; j++){
            if (uscore[i] == score[j]){
                printf("%s rank is %d\n", name[i], j + 1);
            }
        }
    }
    
    return 0;
}