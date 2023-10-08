#include <stdio.h>

void decimal_para_binario(int decimal) {
    if (decimal > 0) {
        decimal_para_binario(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    int decimal;
    printf("Digite um numero decimal: ");
    scanf("%d", &decimal);
    printf("O numero %d em binário é: ", decimal);
    decimal_para_binario(decimal);
    printf("\n");
    return 0;
}
