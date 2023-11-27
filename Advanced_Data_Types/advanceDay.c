#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

/* add your function definitions here */
void readDate(struct date * ptr){
    scanf("%d", &ptr->year);
    scanf("%d", &ptr->month);
    scanf("%d", &ptr->day);
}

void printDate(struct date today){
    if (today.month < 10){
        printf("0%d/", today.month);
    } else if (today.month < 13) {
        printf("%d/", today.month);
    } else {
        printf("01/");
    }
    
    if (today.day < 10){
        printf("0%d/", today.day);
    } else if (today.month < 32) {
        printf("%d/", today.day);
    } else {
        printf("01/");
    }
    
    printf("%d\n", today.year);
}

struct date advanceDay(struct date today){
    if (((today.month % 2 == 1) && today.month < 8) || ((today.month % 2 == 0) && today.month >= 8)){
        if (today.day == 31){
            today.day = 1;
            today.month++;
            if (today.month == 13){
                today.month = 1;
                today.year++;
            }
        } else {
            today.day++;
        }
    }
    
    if (((today.month % 2 == 0) && today.month < 8 && today.month != 2) || ((today.month % 2 == 1) && today.month >= 8)){
        if (today.day == 30){
            today.day = 1;
            today.month++;
            if (today.month == 13){
                today.month = 1;
                today.year++;
            }
        } else {
            today.day++;
        }
    }
    
    if (today.month == 2){
        if (today.year % 400 == 0){
            if (today.day == 29){
                today.day = 1;
                today.month++;
                if (today.month == 13){
                    today.month = 1;
                    today.year++;
                }
            } else {
                today.day++;
            }   
        } else if (today.year % 100 == 0){
            if (today.day == 28){
                today.day = 1;
                today.month++;
                if (today.month == 13){
                    today.month = 1;
                    today.year++;
                }
            } else {
                today.day++;
            }   
        } else if (today.year % 4 == 0){
            if (today.day == 29){
                today.day = 1;
                today.month++;
                if (today.month == 13){
                    today.month = 1;
                    today.year++;
                }
            } else {
                today.day++;
            }
        }
    }
    
    return today;
}