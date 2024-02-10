#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ERROR 0.0001

double function(float x){
    return (pow(x,3)-6*x+2);
}

int main(){
    float guess1, guess2;
    printf("Enter the first and second guesses:");
    scanf("%f%f", &guess1, &guess2);

    if (function(guess1)*function(guess2) >= 0){
        printf("Invalid guesses.");
        exit(1);
    }

    float random;
    double err;

    do{
        printf("%f\t\t%f\t\t", guess1, guess2);

        random = (guess1 + guess2)/2;
        printf("%f\t\t", random);

        if (function(guess2) * function(random) < 0 ){
            guess1 = random;
        }
        else{
            guess2 = random;
        }

        err = fabs((guess2 - guess1) / guess2);
        printf("%f\n", err);
    }while(err > ERROR);

    printf("\nHence, the root is %f.", random);
}