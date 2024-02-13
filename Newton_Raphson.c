#include<stdio.h>
#include<math.h>

#define ERROR 0.00001

#define f(x) (x*sin(x) + cos(x))
#define fd(x) (x*cos(x))

int main(){
    float guess, root, err;

    printf("Enter the initial guess: ");
    scanf("%f", &guess);

    do{
        root = guess - f(guess)/fd(guess);

        printf("%f\t\t", guess);
        printf("%f\t\t", f(guess));
        printf("%f\t\t", fd(guess));
        printf("%f\n", root);

        guess = root;

        err = fabs(f(root));
    }while(err > ERROR);

    printf("\n");
    printf("The root of the given function is %f", root);
}