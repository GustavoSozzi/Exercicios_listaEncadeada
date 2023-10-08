/*Elabore um
subprograma que calcule o valor da série a seguir. Utilizar tantos termos quantos forem necessários
para que a precisão da resposta seja de 0,01. Indique quantos termos foram usados. O subprograma
deve ser recursivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calcularSerie(int numerador, int denominador, int termo, double soma) {
    if (termo == 0) {
        return soma;
    } else {
        double fracao = (double)numerador / denominador;
        soma += fracao;
        numerador--;
        denominador += 7;
        return calcularSerie(numerador, denominador, termo - 1, soma);
    }
}



int main() {
    int numerador = 70, denominador = 7, termo = 1;
    double soma = 0.0, precisao = 0.01, erro = 0.0;
    do {
        soma = calcularSerie(numerador, denominador, termo, soma);
        erro = fabs(soma - 18.564);
        printf("termo %d: %.3f (erro=%.3f)\n", termo, soma, erro);
        termo++;
    } while (erro > precisao);
    printf("A precisao de %.2f foi atingida com %d termos.\n", precisao, termo - 1);
    return 0;
}





