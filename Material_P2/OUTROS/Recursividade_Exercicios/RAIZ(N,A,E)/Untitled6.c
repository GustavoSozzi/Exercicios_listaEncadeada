#include <stdio.h>
#include <math.h> //para o uso do fabs

double Raiz(double N, double A, double E) {
    double nova_aprox = (A * A + N) / (2 * A); // cálculo da nova aproximação
    double erro = fabs(nova_aprox * nova_aprox - N); // cálculo do erro, funcao pabs para utilizar apenas o valor absoluto independente ser positivo ou negativo

    if (erro < E) { // critério de parada da recursão
        return nova_aprox;
    } else {
        return Raiz(N, nova_aprox, E); // chamada recursiva com a nova aproximação
    }
}

int main() {
    double N, A, E, raiz;
    printf("Digite o número cuja raiz quadrada deseja calcular: ");
    scanf("%lf", &N);
    printf("Digite a aproximação inicial para a raiz: ");
    scanf("%lf", &A);
    printf("Digite o valor máximo de erro admissível: ");
    scanf("%lf", &E);

    raiz = Raiz(N, A, E); // chamada da função Raiz

    printf("A raiz quadrada de %lf é: %lf\n", N, raiz);
    return 0;
}
