#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char marca[31];
    int tipo; //1-novo e 2-usado
    int ano_fab;
    int comb;
    float preco;
}CARROS;

int main(){

    int op;

    do{
        printf("\nMenu de opções\n");
        printf("1 - Inserir carro no cadastro\n");
        printf("2 - Retirar carro do cadastro\n");
        printf("3 - Listar todos os carros disponiveis para venda\n");
        printf("4 - Listar dados de um carro\n");
        printf("5 - Listar todos os carros de uma marca/tipo\n");
        printf("6 - Parar o processamento\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);

        switch(op){

        case 1:
                inserir_carro();
                break;
            case 2:
                retirar_carro();
                break;
            case 3:
                listar_carros_disponiveis();
                break;
            case 4:
                listar_dados_carro();
                break;
            case 5:
                listar_carros_por_marca();
                break;
            case 6:
                parar_processamento();
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }


    }while(op!=6);

    return 0;
}

void inserir_carro(){

    CARROS carro;
    int codigo;
    codigo = 1;
    FILE *arq = fopen("CARROS.TXT", "a"); //abrindo no modo final de arquivo.

    if (arq == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

        printf("Digite a marca do carro: ");
        scanf("%30s", carro.marca);
        fflush(stdin);
        printf("Digite o tipo do carro (1 - NOVO / 2 - USADO): ");
        scanf("%d", &carro.tipo);
        fflush(stdin);
        printf("Digite o ano de fabricacao do carro: ");
        scanf("%d", &carro.ano_fab);
        fflush(stdin);
        printf("Digite o tipo de combustivel do carro (1 - Gasolina / 2 - Alcool / 3 - Diesel): ");
        scanf("%d", &carro.comb);
        fflush(stdin);
        printf("Digite o preco de venda do carro: ");
        scanf("%f", &carro.preco);
        fflush(stdin);
        printf("O seu codigo e: %d", codigo);

        fseek(arq, 0, SEEK_END); // Move o cursor para o último código registrado
        codigo++; //incrementa o codigo;

        fprintf(arq, "%d %s %d %d %d %.2f\n", codigo, carro.marca, carro.tipo, carro.ano_fab, carro.comb, carro.preco);

        printf("\nCarro cadastrado com sucesso.\n");
}

void retirar_carro(){
    CARROS carro;
    FILE *arq = fopen("CARROS.txt", "r+");
    FILE *temp = fopen("temp.txt", "w");

    if(arq == NULL){
        printf("\nerro");
    }

    int codigo, codigo_arq;

    printf("\ndigite o codigo a ser excluido");
    scanf("%d", &codigo);

    while(!feof(arq)){
        fscanf(arq, "%d %s %d %d %d %f", &codigo_arq, carro.marca, &carro.tipo, &carro.ano_fab, &carro.comb, &carro.preco);

        if(codigo |= codigo_arq){
            fprintf(arq, "%s %d %d %d %f", carro.marca, carro.tipo, carro.ano_fab, carro.comb, carro.preco);
        }
    }

    fclose(arq);
    fclose(temp);

    remove("CARROS.TXT");
    rename("temp.txt", "CARROS.TXT"); //removendo e substituindo

    printf("\nCarro excluido com sucesso.\n");

}

void listar_carros_disponiveis(){

    CARROS carro;
    FILE *arq = fopen("CARROS.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

    printf("\nCarros disponiveis para venda:\n");

    while(!feof(arq)){
        fscanf(arq, "%s %d %d %f %d", carro.marca, carro.tipo, &carro.ano_fab, &carro.comb, &carro.preco);

         if (carro.tipo == 1) { // Verifica se o carro é novo
            printf("Marca: %s\n", carro.marca);
            printf("Ano de fabricacao: %d\n", carro.ano_fab);
            printf("Tipo de combustivel: %d\n", carro.comb);
            printf("Preco de venda: %.2f\n", carro.preco);
            printf("\n");
        }
    }
}

void listar_dados_carro() {
    int codigo, codigo_arq;
    CARROS carro;

    FILE *arq = fopen("CARROS.txt", "r");

    if (arq == NULL) {
        printf("\nErro ao abrir arquivo.\n");
        return;
    }

    printf("\nDigite o codigo do carro: ");
    scanf("%d", &codigo);

    while (!feof(arq)) {
        fscanf(arq, "%d %s %d %d %d %f", &codigo_arq, carro.marca, &carro.tipo, &carro.ano_fab, &carro.comb, &carro.preco);

        if (codigo == codigo_arq) {
            printf("\nCodigo: %d", codigo_arq);
            printf("\nMarca: %s", carro.marca);
            printf("\nTipo: %d", carro.tipo);
            printf("\nAno de Fabricacao: %d", carro.ano_fab);
            printf("\nTipo de Combustivel: %d", carro.comb);
            printf("\nPreco: %.2f\n", carro.preco);
            fclose(arq);
            return;
        }
    }

    printf("\nNenhum carro encontrado com o codigo %d.\n", codigo);
    fclose(arq);
}

void listar_carros_por_marca() {

    CARROS carro;
    FILE *arq = fopen("CARROS.TXT", "r");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

    char marca_desejada[31];
    printf("Digite a marca desejada: ");
    scanf("%30s", marca_desejada);

    printf("\nCarros da marca %s:\n", marca_desejada);

    while (fscanf(arq, "%s %d %d %d %f", carro.marca, &carro.tipo, &carro.ano_fab, &carro.comb, &carro.preco) != EOF) {
        if (strcmp(carro.marca, marca_desejada) == 0) { //strcmp para comparar as strings, se forem iguais retorna 0
            printf("\nMarca: %s", carro.marca);
            printf("\nTipo: %d", carro.tipo);
            printf("\nAno de fabricacao: %d", carro.ano_fab);
            printf("\nCombustivel: %d", carro.comb);
            printf("\nPreco: %.2f\n", carro.preco);
        }
    }

    fclose(arq);

}

void parar_processamento() {
    printf("Encerrando o programa. Obrigado por utilizar nosso sistema!\n");
    exit(0); // encerra o programa com status de sucesso
}



