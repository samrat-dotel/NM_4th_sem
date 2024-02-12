#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ERROR 0.0001

float func(float x) {
    return x * x * x - 6 * x + 5;
}

int main() {
    float a, b, root, err;

    printf("Enter the initial interval [a, b]: ");
    scanf("%f%f", &a, &b);

    if (func(a) * func(b) > 0) {
        printf("The root doesn't lie within the range.\n");
        exit(1);
    }

    do {
    root = (a * func(b) - b * func(a)) / (func(b) - func(a)); 

    printf("%f\t\t", a);
    printf("%f\t\t", b);
    printf("%f\n", root);

    a = b;
    b = root;

    err = fabs(func(root));
} while (err > ERROR);


    printf("\n");
    printf("The root of the given function is %f", root);
}