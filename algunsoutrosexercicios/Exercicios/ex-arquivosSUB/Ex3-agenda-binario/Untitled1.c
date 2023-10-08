#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char nome[100];
    char telefone[100];
    int dia, mes;
} Agenda;

/*programa de agenda binario para inserir contato, remover contato, pesquisar contato, listas contatos com dada letra, imprimir aniversariantes do mes;
Sempre que o programa for encerrado, os contatos devem ser armazenados em um arquivo binário.
Quando o programa iniciar, os contatos devem ser inicializados com os dados contidos neste arquivo
binário.*/

void inserir_contato(Agenda *agenda, FILE *arq)
{
    printf("\nNome: ");
    scanf(" %[^\n]", agenda->nome);
    fflush(stdin);

    printf("\nTelefone: ");
    scanf(" %[^\n]", agenda->telefone);
    fflush(stdin);

    printf("\nAniversario: ");
    scanf("%d %d", &agenda->dia, &agenda->mes);
    fflush(stdin);

    fwrite(agenda, sizeof(Agenda), 1, arq); // escreve a nova agenda no arquivo
}

void remover_contato(FILE *arq)
{
    Agenda contato;
    char nome[100];
    int encontrado = 0;

    printf("Qual contato deseja remover: ");
    scanf(" %[^\n]", nome);
    fflush(stdin);

    while (fread(&contato, sizeof(Agenda), 1, arq) == 1) // percorre o arquivo
    {
        if (strcmp(contato.nome, nome) == 0) // verifica se o nome do contato lido é igual ao nome buscado
        {
            encontrado = 1;
            printf("\nContato removido:\n");
            printf("Nome: %s\nTelefone: %s\nAniversario: %d/%d\n", contato.nome, contato.telefone, contato.dia, contato.mes);
            // cria uma nova agenda vazia para substituir o contato no arquivo
            Agenda contato_removido;
            strcpy(contato_removido.nome, "");
            strcpy(contato_removido.telefone, "");
            contato_removido.dia = 0;
            contato_removido.mes = 0;
            // volta uma posição no arquivo para sobrescrever o contato anterior com a nova agenda vazia
            fseek(arq, -sizeof(Agenda), SEEK_CUR);
            fwrite(&contato_removido, sizeof(Agenda), 1, arq);
            printf("\nContato removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado)
    {
        printf("\nContato nao encontrado.\n");
    }
}

void listar_contatos(FILE *arq)
{
    Agenda contato;

    printf("\n---LISTANDO TODOS OS CONTATOS---\n");

    rewind(arq); // volta para o início do arquivo

    while(fread(&contato, sizeof(Agenda), 1, arq) == 1)
    {
        printf("\nNome: %s", contato.nome);
        printf("\nTelefone: %s", contato.telefone);
        printf("\nAniversario: %d/%d", contato.dia, contato.mes);
        printf("\n-----------------------------\n");
    }
}

void listar_contatos_letra(FILE *arq, char letra)
{
    Agenda contato;

    printf("\n---LISTANDO CONTATOS COM A LETRA %c---\n", letra);

    rewind(arq); // volta para o início do arquivo

    while(fread(&contato, sizeof(Agenda), 1, arq) == 1)
    {
        if(contato.nome[0] == letra)
        {
            printf("\nNome: %s", contato.nome);
            printf("\nTelefone: %s", contato.telefone);
            printf("\nAniversario: %d/%d", contato.dia, contato.mes);
            printf("\n-----------------------------\n");
        }
    }
}

void imprimir_aniversariantes_mes(FILE *arq)
{
    Agenda contato;
    int mes_atual;

    printf("\n---ANIVERSARIANTES DO MES---\n");

    // obtém o mês atual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    mes_atual = tm.tm_mon + 1;

    rewind(arq); // volta para o início do arquivo

    while(fread(&contato, sizeof(Agenda), 1, arq) == 1)
    {
        if(contato.mes == mes_atual)
        {
            printf("\nNome: %s", contato.nome);
            printf("\nTelefone: %s", contato.telefone);
            printf("\nAniversario: %d/%d", contato.dia, contato.mes);
            printf("\n-----------------------------\n");
        }
    }
void pesquisar_contato(FILE *arq)
{
    Agenda contatos;
    char nome[100];
    int encontrou = 0;

    printf("\nDigite o nome do contato que deseja pesquisar: ");
    scanf("%s", nome);

    while(fread(&contatos, sizeof(Agenda), 1, arq) == 1) // percorre o arquivo binário
    {
        if(strcmp(contatos.nome, nome) == 0) // compara o nome do contato com o nome pesquisado
        {
            printf("\nNome: %s", contatos.nome);
            printf("\nTelefone: %s", contatos.telefone);
            printf("\nAniversario: %d/%d\n", contatos.dia, contatos.mes);
            encontrou = 1;
            break;
        }
    }

    if(!encontrou)
        printf("\nContato nao encontrado.\n");
}



int main()
{
    Agenda agenda;
    int op=0;

    FILE *arq = fopen("arquivo.bin", "rb+"); //arquivo binario para leitura e escrita;

    if(arq == NULL)
    {
        printf("\nerro em arquivo");
        exit(1);
    }

    while(op!=-1)
    {
        printf("-1-sair\n1-inserir contato\n2-remover contato\n3-pesquisar contato pelo nome\n4-listar todos contatos\n5-listar contatos cujo nome inicia com uma letra\n6-imprimir aniversariantes do mes\n");
        scanf("%d", &op);
        fflush(stdin);

        switch(op)
        {
            case 1:
                inserir_contato(&agenda);
                fwrite(&agenda, sizeof(Agenda), 1, arq);
                break;

            case 2:
                remover_contato(arq);
                break;

            case 3:
                pesquisar_contato(arq);
                break;

            case 4:
                listar_contatos(arq);
                break;

            case 5:
                listar_contatos_por_letra(arq);
                break;

            case 6:
                imprimir_aniversariantes_do_mes(arq);
                break;

            case -1:
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    fclose(arq);

    return 0;
}





/*REMOÇÃO COM O FSEEK*/

// abrir arquivo binário para leitura e escrita
//FILE *arquivo = fopen("contatos.bin", "rb+");

// mover o ponteiro de posição para a posição desejada
//fseek(arquivo, pos * sizeof(Agenda), SEEK_SET);

// criar uma nova agenda para substituir o contato na posição atual
/*Agenda contato_removido;
strcpy(contato_removido.nome, "");
strcpy(contato_removido.telefone, "");
contato_removido.dia = 0;
contato_removido.mes = 0;

// escrever a nova agenda na posição atual, sobrescrevendo o contato anterior
fwrite(&contato_removido, sizeof(Agenda), 1, arquivo);

// fechar o arquivo
fclose(arquivo);*/


