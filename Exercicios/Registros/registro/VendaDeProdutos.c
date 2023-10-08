#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char nome[50]; // \0 delimite o fim da caractere, no caso cabe 49 letras ou caracteres
    char efEnergetica;
    char marca[50];
    float valor;
    int quantidade;
}Eletronico;

Eletronico estoque[3];

Eletronico ler(){  //sem void pois iremos retornar eletronico

    Eletronico el;


    printf("\nDigite o codigo do Produto: ");
    scanf("%d", &el.codigo);
    scanf("%*c");  //limpando buffer do teclado, para n dar erro em entrada de dados

    printf("\nQual o nome do eletronico: ");
    fgets(el.nome, 49, stdin);    //funcao manipular arquivos, ler entrada de espacos e enter sem cortar palavras
    //stdin lendo caracteres do teclado

    printf("\n Qual a eficiencia energetica: ");
    scanf("%c", &el.efEnergetica);
    scanf("%*c");  //limpando buffer do teclado, para n dar erro em entrada de dados

    printf("\n Qual a marca: ");
    fgets(el.marca, 49, stdin);

    printf("qual o valor: ");
    scanf("%f", &el.valor);

    printf("qual a quantidade: ");
    scanf("%d", &el.quantidade);

    return el;
}

void imprimirEletronico(Eletronico e){

    printf("\n codigo: %d\n", e.codigo);
    printf("\tnome: %s", e.nome);
    printf("\tef energetica: %c\n", e.efEnergetica);
    printf("\t5marca: %s", e.marca);
    printf("\tvalor %2.f: ", e.valor);
    printf("\t quantidade: %d", e.quantidade);
}

void ImprimirCodigoNome(){
    int i;
     for(i=0; i < 3; i++){
        printf("\nCodigo %d, Nome %s", estoque[i].codigo, estoque[i].nome);
    }

}

int vender(){   //funcao para vender retorna se o produto esta disponivel

    int cod, i;

    ImprimirCodigoNome();

    printf("qual o codigo do produto: ");
    scanf("%d", &cod);

    for(i=0; i<3; i++){
        if(cod == estoque[i].codigo){
            if(estoque[i].quantidade > 0){
                printf("\nVenda realizada com sucesso!!!");
                estoque[i].quantidade--;
                return 1;
            }
        }

        return 0;
}

int AtualizarEstoque(){   //funcao para vender retorna se o produto esta disponivel

    int cod, i, qtd;

    ImprimirCodigoNome();

    printf("qual o codigo do produto: ");
    scanf("%d", &cod);

    for(i=0; i<3; i++){
        if(cod == estoque[i].codigo){
            printf("\ndigite a quantidade: ");
            scanf("%d", &qtd);
            estoque[i].quantidade += qtd;
            return 1;
        }

        return 0;
}



int main(){

    Eletronico eltro = ler();
    imprimirEletronico(eltro);


    int i, op;

    for(i=0; i<3; i++){
        estoque[i] = ler();
    }

    for(i=0; i<3; i++){
        imprimirEletronico(estoque[i]);
    }

    printf("\nEscolha a tarefa\n\t1 - Imprimir estoque\n\t2 - Vender\n\t3 - Atualizar estoque\n\t0 - Sair\n");
    scanf("%d", &op);
    while(op != 0) {
        switch(op) {
        case 1: // imprimir todos os eletrônicos
            for(i = 0; i < 3; i++) {
                printf("\nEletronico indice %d\n", i);
                imprirEletronico(estoque[i]);
            }
            break;
        case 2: // vender um eletrônico
            if(vender())
                printf("\n----- Venda realizada com sucesso!!! -----\n");
            else
                printf("\n***** Nao foi possivel realizar a venda. Verifique seu estoque. *****\n");
            break;
        case 3: // atualizar estoque de um eletrônico
            if(atualizarEstoque())
                printf("\nEstoque atualidado!!!\n");
            else
                printf("\nErro ao atualizar o estoque!\n");
            break;
        default:
            printf("\nOpcao invalida!!!\n");
        }
        // imprime na tela o menu de opções
        printf("\nEscolha a tarefa\n\t1 - Imprimir estoque\n\t2 - Vender\n\t3 - Atualizar estoque\n\t0 - Sair\n");
        scanf("%d", &op);
    }

    return 0;
}
