#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ERROR 0.0001

float func(float x) {
    return x * x * x - 6 * x + 5;
}

int main() {
    float guess1, guess2, a, b, root, err;

    printf("Enter the two initial guesses: ");
    scanf("%f%f", &guess1, &guess2);

    if (func(guess1) * func(guess2) > 0) {
        printf("The root doesn't lie within the range.\n");
        exit(1);
    }

    if (func(guess1) < 0) {
        a = guess1;
        b = guess2;
    } else {
        a = guess2;
        b = guess1;
    }

    do {
        float denominator = func(b) - func(a);

        if (fabs(denominator) < ERROR) {
            printf("Denominator is too small, breaking out of the loop.\n");
            break;
        }

        root = (a * func(b) -  b * func(a)) / denominator;

        if (func(root) > 0) {
            b = root;
        } else {
            a = root;
        }

        err = fabs((b - a) / fabs(b));
    } while (err > ERROR);

    printf("The root is %f\n", root);

    return 0;
}
