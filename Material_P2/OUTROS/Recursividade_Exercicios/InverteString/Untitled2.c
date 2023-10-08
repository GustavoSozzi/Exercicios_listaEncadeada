
/*Desenvolva um
subprograma recursivo para inverter uma string recebida como parâmetro*/


#include <stdio.h>
#include <string.h>

void inverte_string(char *str, int inicio, int fim) {
    char temp;
    if (inicio >= fim) {
        // Caso base: a string já foi invertida completamente
        return;
    }
    // Troca os caracteres nas posições inicio e fim
    temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    // Chama a função recursivamente para inverter a parte interna da string
    inverte_string(str, inicio+1, fim-1);
}

int main() {
    char str[] = "exemplo";
    printf("String original: %s\n", str);
    inverte_string(str, 0, strlen(str)-1); //strlen para o comprimento da string
    printf("String invertida: %s\n", str);
    return 0;
}


