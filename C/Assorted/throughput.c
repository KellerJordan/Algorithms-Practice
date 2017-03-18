#include <stdio.h>
#include <math.h>

double summation(double p, double K) {
    double S = 0;
    for (double n = 0; n <= K; n++)
        S += n * ( (pow(p, n) * (1 - p)) / (1 - pow(p, K + 1)) );
    return S;
}

double formula(double p, double K) {
    return (
        p / (1 - p)
        -
        ((K + 1) * pow(p, K + 1)) / (1 - pow(p, K + 1))
    );
}

int main() {
    double p;
    double K;
    while (1) {
        printf("Enter p: ");
        scanf("%lf", &p);
        printf("Enter K: ");
        scanf("%lf", &K);

        printf("Result of using summation(): %.3f\n", summation(p, K));
        printf("Result of using formula(): %.3f\n", formula(p, K));
    }
}