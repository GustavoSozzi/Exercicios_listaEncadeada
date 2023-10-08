#include <stdio.h>
#include <math.h> //para o uso do fabs

double Raiz(double N, double A, double E) {
    double nova_aprox = (A * A + N) / (2 * A); // c�lculo da nova aproxima��o
    double erro = fabs(nova_aprox * nova_aprox - N); // c�lculo do erro, funcao pabs para utilizar apenas o valor absoluto independente ser positivo ou negativo

    if (erro < E) { // crit�rio de parada da recurs�o
        return nova_aprox;
    } else {
        return Raiz(N, nova_aprox, E); // chamada recursiva com a nova aproxima��o
    }
}

int main() {
    double N, A, E, raiz;
    printf("Digite o n�mero cuja raiz quadrada deseja calcular: ");
    scanf("%lf", &N);
    printf("Digite a aproxima��o inicial para a raiz: ");
    scanf("%lf", &A);
    printf("Digite o valor m�ximo de erro admiss�vel: ");
    scanf("%lf", &E);

    raiz = Raiz(N, A, E); // chamada da fun��o Raiz

    printf("A raiz quadrada de %lf �: %lf\n", N, raiz);
    return 0;
}
