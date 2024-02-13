#include <stdio.h>
#include <math.h>

#define ERROR 0.00001

#define f(x) (x * x - 4 * x - 9)
#define g(x) (9/(x-4))

int main() {
    float guess, root;
    int iteration = 0, max_iteration;

    printf("Enter your initial guess:");
    scanf("%f", &guess);

    printf("Enter the max number of iterations:");
    scanf("%d", &max_iteration);

    do {
        root = g(guess);
        iteration++;

        printf("%d\t\t", iteration);
        printf("%f\t\t", guess);
        printf("%f\n", root);

        guess = root;
    } while(fabs(f(root)) > ERROR && iteration < max_iteration);

    if (iteration >= max_iteration) {
        printf("Maximum iterations reached\n");
    } else {
        printf("Root found after %d iterations: %f\n", iteration, root);
    }

    return 0;
}
