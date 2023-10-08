#include <stdio.h>
#include <stdlib.h>
/*questao 1. crie algoritmo para cadastro de informacaoes de uma empresa*/

typedef struct local{
    char cidade[32];
    char estado[32]
}Local;

typedef struct{
    char nome[32];
    char cnpj[16];
    Local local;  //struct apontando para outra struct local
}Empresa;

int main(){
    Empresa emp;

    printf("Nome: ");
    scanf("%s", emp.nome);

    printf("CNPJ: ");
    scanf("%s", emp.cnpj);

    printf("Cidade: ");
    scanf("%s", emp.local.cidade);

    printf("estado: ");
    scanf("%s", emp.local.estado);

}
