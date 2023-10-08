#include <stdio.h>

float produto_vetor(float v[], int n)
{
    if (n == 0) {
        return 1; // caso base: vetor vazio, retorna 1
    } else {
        return v[n-1] * produto_vetor(v, n-1); // chama a função recursivamente com o vetor reduzido
    }
}

int main()
{
    float vetor[4] = {1, 2, 3, 4};
    int tamanho = 4;

    float resultado = produto_vetor(vetor, tamanho);
    printf("O produto dos elementos do vetor e: %.2f", resultado);

    return 0;
}
