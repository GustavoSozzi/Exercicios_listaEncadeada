#include <stdio.h>

int main() {
    int numbers[100];
    int sum = 0;

    // abrindo o arquivo para leitura
    FILE *file = fopen("binario.txt", "rb"); //lendo o arquivo binario

    // lendo os números do arquivo
    fread(numbers, sizeof(int), 100, file);

    // fechando o arquivo
    fclose(file);

    // calculando a soma dos números
    for (int i = 0; i < 100; i++) {
        sum += numbers[i];
    }

    // mostrando a soma
    printf("Soma dos numeros: %d\n", sum);

    return 0;
}
