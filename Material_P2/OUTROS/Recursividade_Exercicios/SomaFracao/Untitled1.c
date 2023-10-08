#include <stdio.h>

double sum_series() { //versao normal
    double sum = 0;
    int numerator = 1, denominator = 2;
    for (int i = 1; i <= 20; i++) {
        sum += (double)numerator / denominator;
        numerator++;
        denominator += i;
    }
    return sum;
}

double sum_series_recursive(int numerator, int denominator, int term) {
    if (term == 1) {
        return (double)numerator / denominator;
    } else {
        return (double)numerator / denominator + sum_series_recursive(numerator + 1, denominator + term, term - 1);
    }
}

int main() {
    printf("A soma da série é: %f", sum_series());

    printf("A soma da série é: %f", sum_series_recursive(1, 2, 20));


    return 0;
}
