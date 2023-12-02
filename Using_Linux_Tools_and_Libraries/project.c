#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct star {
    char name[50];
    int temperature;
    double luminosity;
    double radius;
    char classification;
};

void printStars(struct star mystars[], int N); 
int readStars(struct star * starname);
void computeRadii(struct star * starname, int n);
void classifyStars(struct star * starname, int n);

// Do not modify the main() function!
int main(void) {
    struct star mystars[50];
    int N;

    N = readStars(mystars);
    computeRadii(mystars, N);
    classifyStars(mystars, N);
    printStars(mystars, N);

    return 0;
}

// Do not modify the printStars() function!
void printStars(struct star mystars[], int N) {
    int i;
    for (i=0; i<N; i++) {
        printf("%s is a ", mystars[i].name);
        if (mystars[i].classification == 'M') {
        	printf("Main Sequence Star\n");
        } else if (mystars[i].classification == 'G') {
            printf("Giant\n");
        } else if (mystars[i].classification == 'S') {
        	printf("Supergiant\n");
        } else if (mystars[i].classification == 'W') {
        	printf("White Dwarf\n");
        } else if (mystars[i].classification == 'N') {
        	printf("Unclassified Star\n");
        } else {
        	printf(" !!! Warning: '%c' not a valid classification code!!!\n", mystars[i].classification);
        }
        printf("Temp = %d Kelvin, Lum = %.4lf Sol, Rad = %.2lf * R_Sun\n\n", mystars[i].temperature, mystars[i].luminosity, mystars[i].radius);
    }
}

int readStars(struct star * starname) {
    char nama[10000];
    int temp = 0;
    double bright = 0.00;
    int j = 0;
    
    FILE *ifile;
    ifile = fopen("stardata.txt", "r");

    while (fscanf(ifile, "%s", nama) != EOF){
        strcpy((starname + j)->name, nama);
        fscanf(ifile, "%d", &temp);
        (starname + j)->temperature = temp;
        fscanf(ifile, "%lf", &bright);
        (starname + j)->luminosity = bright;
        j++;
    }

    return j;
}

void computeRadii(struct star * starname, int n) {
    int k = 0;
    for (k = 0; k < n; k++) {
        int T = (starname + k)->temperature;
        double L = (starname + k)->luminosity;
        double R = pow((3500.00 / T), 2) * sqrt(L);
        (starname + k)->radius = R;
    }
}

void classifyStars(struct star * starname, int n) {
    /* Main Sequence (M): 
    Luminosity between 10^-2 and 10^6 times that of the sun;
    Radius between 0.1 and 10 times that of the sun.

    Giants (G):  
    Luminosity between 10^3 and 10^5 times that of the sun;
    Radius between 10 and 100 times that of the sun.

    Supergiants (S):
    Luminosity between 10^5 and 10^6 times that of the sun;
    Radius greater than 100 times that of the sun.

    White Dwarfs (W):
    Radius less than 0.01 times that of the sun.

    Neither (N):
    Anything else */

    int m = 0;

    for (m = 0; m < n; m++){
        if ((pow(10, -2) <= ((starname + m)->luminosity) && ((starname + m)->luminosity) <= pow(10, 6)) && (0.1 <= ((starname + m)->radius) && ((starname + m)->radius) <= 10)){
            (starname + m)->classification = 'M';
        } else if ((pow(10, 3) <= ((starname + m)->luminosity) && ((starname + m)->luminosity) <= pow(10, 5)) && (10 <= ((starname + m)->radius) && ((starname + m)->radius) <= 100)){
            (starname + m)->classification = 'G';
        } else if ((pow(10, 5) <= ((starname + m)->luminosity) && ((starname + m)->luminosity) <= pow(10, 6)) && (((starname + m)->radius) > 100)){
            (starname + m)->classification = 'S';
        } else if (0.1 > ((starname + m)->radius)){
            (starname + m)->classification = 'W';
        } else {
            (starname + m)->classification = 'N';
        }
    }
}
