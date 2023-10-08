//--------------ARCHIVES---------------

/*
        Aula 208: Como escrever em arquivo texto com a funçăo fputc?

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

int main(){

    FILE *file;
    char letra;

    file = fopen("conto.txt","w");

    if(file){
        printf("\nDigite um texto e pressione ENTER ao finalizar!");
        scanf("%c", &letra);
        while(letra != '\n'){
            fputc(letra, file);
            scanf("%c", &letra);
        }
        fclose(file);
    }
    else
        printf("\n\t--> ERRO ao abrir arquivo!\n");

    return 0;
}

/*
        Aula 209: Como ler em arquivo texto com a função fgetc?

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

int main(){

    FILE *file;
    char letra;

    file = fopen("conto.txt","w+");

    if(file){
        printf("\nDigite um texto e pressione ENTER ao finalizar!");
        scanf("%c", &letra);
        while(letra != '\n'){
            fputc(letra, file);
            scanf("%c", &letra);
        }

        rewind(file);

        printf("\n\tTexto lido do arquivo:\n");
        while(!feof(file)){
            letra = fgetc(file);
            printf("%c", letra);
        }

        fclose(file);
    }
    else
        printf("\n\t--> ERRO ao abrir arquivo!\n");

    return 0;
}

/*
        Aula 210: Organizando nosso código em procedimentos

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

#include <stdio.h>
#include <stdlib.h>

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char letra;

    if(file) {
        printf("\nDigite um texto e pressione ENTER ao finalizar!");
        scanf("%c", &letra);
        while(letra != '\n') {
            fputc(letra, file);
            scanf("%c", &letra);
        }
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}

void ler(char f[]) {
    FILE *file = fopen(f, "r");
    char letra;

    if(file){
        printf("\n\tTexto lido do arquivo:\n");
        while(!feof(file)) {
            letra = fgetc(file);
            printf("%c", letra);
        }

        fclose(file);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);
    ler(nome);

    return 0;
}

/*
        Aula 211: Como escrever linhas de texto com a função fputs?

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char texto[500];

    if(file) {
        printf("Digite uma frase ou 1 caracter para finalizar:\n");
        scanf("%499[^\n]", texto);
        scanf("%c"); // limpa o ENTER que ficou no buffer do teclado
        while(strlen(texto) > 1){
            fputs(texto, file);
            fputc('\n', file);
            scanf("%499[^\n]", texto);
            scanf("%c");
        }
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);

    return 0;
}

/*
        Aula 212: Como ler linhas de texto com a função fgets?

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char texto[500];

    if(file) {
        printf("Digite uma frase ou 1 caracter para finalizar:\n");
        scanf("%499[^\n]", texto);
        scanf("%c");
        while(strlen(texto) > 1){
            fputs(texto, file);
            fputc('\n', file);
            scanf("%499[^\n]", texto);
            scanf("%c");
        }
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}

void ler(char f[]) {
    FILE *file = fopen(f, "r");
    char texto[500];

    if(file){
        printf("\n\tTexto lido do arquivo\n");
        while(!feof(file)){
            if(fgets(texto, 499, file))
                printf("\n--> %s", texto);
        }
        fclose(file);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);
    ler(nome);

    return 0;
}

/*
        Aula 213: Como escrever em um arquivo texto com a função fprintf?

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char nome[100];
    int opcao, idade;
    float altura;

    if(file) {
        do{
            printf("Digite nome, idade e altura: ");
            scanf("%99[^\n]%d%f", nome, &idade, &altura);
            fprintf(file, "%s %d %.2f\n", nome, idade, altura);
            printf("\nDigite 1 para inserir outro registro. ");
            scanf("%d", &opcao);
            scanf("%c");
        }while(opcao == 1);
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);

    return 0;
}

/*
        Aula 213: Como escrever em um arquivo texto com a função fprintf?

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char nome[100];
    int opcao, idade;
    float altura;

    if(file) {
        do{
            printf("Digite nome, idade e altura: ");
            scanf("%99[^\n]%d%f", nome, &idade, &altura);
            fprintf(file, "%s %d %.2f\n", nome, idade, altura);
            printf("\nDigite 1 para inserir outro registro. ");
            scanf("%d", &opcao);
            scanf("%c");
        }while(opcao == 1);
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);

    return 0;
}

/*
        Aula 214: Como ler um arquivo de texto com a função fscanf?

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char nome[100];
    int opcao, idade;
    float altura;

    if(file) {
        do{
            printf("Digite nome, idade e altura: ");
            scanf("%100[^\n]%d%f", nome, &idade, &altura);
            fprintf(file, "%s %d %.2f\n", nome, idade, altura);
            printf("\nDigite 1 para inserir outro registro. ");
            scanf("%d", &opcao);
            scanf("%c");
        }while(opcao == 1);
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}

void ler(char f[]) {
    FILE *file = fopen(f, "r");
    char nome[100];
    int idade;
    float altura;

    if(file){
        printf("\tDados lidos do arquivo:\n");
        while(fscanf(file, "%s%d%f", nome, &idade, &altura) != -1)
            printf("\n\tNome: %s\n\tIdade: %d\n\tAltura: %.2f\n", nome, idade, altura);
        fclose(file);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}

int main() {

    char nome[] = {"conto.txt"};

    escrever(nome);
    ler(nome);

    return 0;
}

/*
          AGENDA DE ANIVERSÁRIOS

          Código escrito por Wagner Gaspar
          Junho de 2021
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **c, int quant){
    int i;

    printf("\n\t\tLista de Contatos:\n");
    printf("\t--------------------------------\n");
    for(i = 0; i < quant; i++){
        printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t--------------------------------\n");
}

int cadastrar_contato(Contato **c, int quant, int tam){

    if(quant < tam){
        Contato *novo = malloc(sizeof(Contato));

        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[quant] = novo;
        return 1;
    }
    else{
        printf("\n\tImpossivel novo cadastro. Vetor cheio!\n");
        return 0;
    }
}

void alterar_contato(Contato **c, int quant){
    int id;

    imprimir(c, quant);

    printf("\n\tDigite o codigo do contato que deseja alterar: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant){
        Contato *novo = malloc(sizeof(Contato));
        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[id] = novo;
    }
    else
        printf("\n\tCodigo invalido!\n");
}

int main(){

    Contato *agenda[50];
    int opcao, tam = 50, quant = 0;

    do{
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5 - Ler arquivo\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            quant += cadastrar_contato(agenda, quant, tam);
            break;
        case 2:
            alterar_contato(agenda, quant);
            break;
        case 3:
            imprimir(agenda, quant);
            break;
        case 4:

            break;
        case 5:

            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

//          AGENDA DE ANIVERSÁRIOS

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **c, int quant){
    int i;

    printf("\n\t\tLista de Contatos:\n");
    printf("\t--------------------------------\n");
    for(i = 0; i < quant; i++){
        printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t--------------------------------\n");
}

int cadastrar_contato(Contato **c, int quant, int tam){

    if(quant < tam){
        Contato *novo = malloc(sizeof(Contato));

        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[quant] = novo;
        return 1;
    }
    else{
        printf("\n\tImpossivel novo cadastro. Vetor cheio!\n");
        return 0;
    }
}

void alterar_contato(Contato **c, int quant){
    int id;

    imprimir(c, quant);

    printf("\n\tDigite o codigo do contato que deseja alterar: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant){
        Contato *novo = malloc(sizeof(Contato));
        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[id] = novo;
    }
    else
        printf("\n\tCodigo invalido!\n");
}

void salvar(Contato **c, int quant, char arq[]){
    FILE *file = fopen(arq, "w");
    int i;

    if(file){
        fprintf(file, "%d\n", quant);
        for(i = 0; i < quant; i++){
            fputs(c[i]->nome, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
}

int main(){

    Contato *agenda[50];
    char arquivo[] = {"agenda.txt"};
    int opcao, tam = 50, quant = 0;

    do{
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5 - Ler arquivo\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            quant += cadastrar_contato(agenda, quant, tam);
            break;
        case 2:
            alterar_contato(agenda, quant);
            break;
        case 3:
            imprimir(agenda, quant);
            break;
        case 4:
            salvar(agenda, quant, arquivo);
            break;
        case 5:

            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

/*
          AGENDA DE ANIVERSÁRIOS

          Código escrito por Wagner Gaspar
          Junho de 2021
*/

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **c, int quant){
    int i;

    printf("\n\t\tLista de Contatos:\n");
    printf("\t--------------------------------\n");
    for(i = 0; i < quant; i++){
        printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t--------------------------------\n");
}

int cadastrar_contato(Contato **c, int quant, int tam){

    if(quant < tam){
        Contato *novo = malloc(sizeof(Contato));

        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[quant] = novo;
        return 1;
    }
    else{
        printf("\n\tImpossivel novo cadastro. Vetor cheio!\n");
        return 0;
    }
}

void alterar_contato(Contato **c, int quant){
    int id;

    imprimir(c, quant);

    printf("\n\tDigite o codigo do contato que deseja alterar: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant){
        Contato *novo = malloc(sizeof(Contato));
        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[id] = novo;
    }
    else
        printf("\n\tCodigo invalido!\n");
}

void salvar(Contato **c, int quant, char arq[]){
    FILE *file = fopen(arq, "w");
    int i;

    if(file){
        fprintf(file, "%d\n", quant);
        for(i = 0; i < quant; i++){
            fputs(c[i]->nome, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
}

int ler_arquivo(Contato **c, char arq[]){
    FILE *file = fopen(arq, "r");
    int quant = 0, i;
    Contato *novo = malloc(sizeof(Contato));

    if(file){
        fscanf(file, "%d\n", &quant);
        for(i = 0; i < quant; i++){
            //fgets(novo->nome, 50, file);
            fscanf(file, "%50[^\n]", novo->nome);
            fscanf(file, "%d %d %d\n", &novo->dia, &novo->mes, &novo->ano);
            c[i] = novo;
            novo = malloc(sizeof(Contato));
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
    return quant;
}

int main(){

    Contato *agenda[50];
    char arquivo[] = {"agenda.txt"};
    int opcao, tam = 50, quant = 0;

    do{
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5 - Ler arquivo\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            quant += cadastrar_contato(agenda, quant, tam);
            break;
        case 2:
            alterar_contato(agenda, quant);
            break;
        case 3:
            imprimir(agenda, quant);
            break;
        case 4:
            salvar(agenda, quant, arquivo);
            break;
        case 5:
            quant = ler_arquivo(agenda, arquivo);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

/*
        Aula 218: Escrevendo em arquivo binário com a função fwrite()

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        wb -> Escrita
        rb -> leitura
        ab -> anexar
        rb+ -> leitura e escrita
        wb+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        ab+ -> leitura e escrita (adiciona ao final do arquivo)
*/

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void escrever(char arq[]){
    Contato c;
    FILE *file = fopen(arq, "ab");

    if(file){
        printf("Digite o nome e a data de nascimento dd mm aaaa: ");
        scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
        fwrite(&c, sizeof(Contato), 1, file);
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int main(){
    char arquivo[] = {"agenda.dat"};

    escrever(arquivo);

    return 0;
}

/*
        Aula 218 e 219: Lendo em arquivo binário com a função fread()

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        wb -> Escrita
        rb -> leitura
        ab -> anexar
        rb+ -> leitura e escrita
        wb+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        ab+ -> leitura e escrita (adiciona ao final do arquivo)
*/

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void escrever(char arq[]){
    Contato c;
    FILE *file = fopen(arq, "ab");

    if(file){
        printf("Digite o nome e a data de nascimento dd mm aaaa: ");
        scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
        fwrite(&c, sizeof(Contato), 1, file);
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

void ler(char arq[]){
    Contato c;
    FILE *file = fopen(arq, "rb");

    if(file){
        while(!feof(file)){
            if(fread(&c, sizeof(Contato), 1, file))
                printf("\nNome: %s\nData: %d/%d/%d\n", c.nome, c.dia, c.mes, c.ano);
        }
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int main(){
    char arquivo[] = {"agenda.dat"};

    escrever(arquivo);
    ler(arquivo);

    return 0;
}

/*
            AGENDA DE ANIVERSÁRIOS

            Código escrito por Wagner Gaspar
            Junho de 2021
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **c, int quant){
    int i;

    printf("\n\t\tLista de Contatos:\n");
    printf("\t--------------------------------\n");
    for(i = 0; i < quant; i++){
        printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t--------------------------------\n");
}

int cadastrar_contato(Contato **c, int quant, int tam){

    if(quant < tam){
        Contato *novo = malloc(sizeof(Contato));

        printf("\nDigite o nome do contato: ");
        scanf("%49[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[quant] = novo;
        return 1;
    }
    else{
        printf("\n\tImpossivel novo cadastro. Vetor cheio!\n");
        return 0;
    }
}

void alterar_contato(Contato **c, int quant){
    int id;

    imprimir(c, quant);

    printf("\n\tDigite o codigo do contato que deseja alterar: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant){
        Contato *novo = malloc(sizeof(Contato));
        printf("\nDigite o nome do contato: ");
        scanf("%49[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[id] = novo;
    }
    else
        printf("\n\tCodigo invalido!\n");
}

void salvar(Contato **c, int quant, char arq[]){
    FILE *file = fopen(arq, "w");
    int i;

    if(file){
        fprintf(file, "%d\n", quant);
        for(i = 0; i < quant; i++){
            fputs(c[i]->nome, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
}

int ler_arquivo(Contato **c, char arq[]){
    FILE *file = fopen(arq, "r");
    int quant = 0, i;
    Contato *novo = malloc(sizeof(Contato));

    if(file){
        fscanf(file, "%d\n", &quant);
        for(i = 0; i < quant; i++){
            //fgets(novo->nome, 50, file);
            fscanf(file, "%50[^\n]", novo->nome);
            fscanf(file, "%d %d %d\n", &novo->dia, &novo->mes, &novo->ano);
            c[i] = novo;
            novo = malloc(sizeof(Contato));
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
    return quant;
}

void salvarB(char arq[], Contato **c, int quant){
    FILE *file = fopen(arq, "wb");
    int i;

    if(file){
        for(i = 0; i < quant; i++)
            fwrite(c[i], sizeof(Contato), 1, file);
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int lerB(char arq[], Contato **c){
    int quant = 0;
    Contato *novo = malloc(sizeof(Contato));
    FILE *file = fopen(arq, "rb");

    if(file){
        while(fread(novo, sizeof(Contato), 1, file)){
            c[quant] = novo;
            quant++;
            novo = malloc(sizeof(Contato));
        }
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
    return quant;
}

int main(){

    Contato *agenda[50];
    char arquivo[] = {"agenda.txt"};
    char arquivo2[] = {"agenda.dat"};
    int opcao, tam = 50, quant = 0;

    do{
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n");
        printf("\t4 - Salvar\n\t5 - Ler arquivo\n\t6 - SalvarB\n\t7 - LerB\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            quant += cadastrar_contato(agenda, quant, tam);
            break;
        case 2:
            alterar_contato(agenda, quant);
            break;
        case 3:
            imprimir(agenda, quant);
            break;
        case 4:
            salvar(agenda, quant, arquivo);
            break;
        case 5:
            quant = ler_arquivo(agenda, arquivo);
            break;
        case 6:
            salvarB(arquivo2, agenda, quant);
            break;
        case 7:
            quant = lerB(arquivo2, agenda);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

// procedimento para alterar um contato

void alterarB(char arq[]){
    FILE *file = fopen(arq, "rb+");
    Contato c;
    int id, i = 1;

    if(file){
        printf("\tLista de contatos:\n");
        printf("\t----------------------------\n");
        while(fread(&c, sizeof(Contato), 1, file)){
            printf("\t%d = %2d/%2d/%4d\t%s\n", i, c.dia, c.mes, c.ano, c.nome);
            i++;
        }
        printf("\t----------------------------\n");

        printf("\n\tDigite o indice do contato que deseja alterar:\n\n");
        scanf("%d", &id);
        getchar();
        id--;

        if(id >= 0 && id < i - 1){
            printf("\tDigite nome e data de nascimento dd mm aaaa: ");
            scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
            fseek(file, id * sizeof(Contato), SEEK_SET);
            fwrite(&c, sizeof(Contato), 1, file);
        }
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

/*
              Como remover / apagar um arquivo com a função remove?

              Código escrito por Wagner Gaspar
              Julho de 2021
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    // nome do arquivo
    char nome[] = {"agenda.txt"};

    // tenta abrir o arquivo para escrita
    FILE *file = fopen(nome, "w");

    if(file){
        printf("\nArquivo aberto com sucesso!\n");
        fclose(file);

        // tenta remover o arquivo agenda.txt
        printf("\nRetorno: %d\n", remove(nome));
    }
    else{
        printf("\nErro ao abrir o arquivo!\n");

        // Ao tentar remover um arquivo que não existe a função retorna o valor -1
        printf("\nRetorno: %d\n", remove(nome));
    }

    return 0;
}


---------------------------------------------


#include <stdio.h>

#define MAX_S 30

int size(char txt[])
{
    int i;
    for (i=0;i<MAX_S && txt[i]!='\0';i++)
    {}

    return i;
}

void  buscarLetra(char *txt,char letra,int pos[])
{
    int i,cont;
    for (i=0,cont=0;i<MAX_S && txt[i]!='\0';i++)
    {
        if (txt[i]==letra)
        {
            pos[cont]=i;
            cont++;
        }
    }
}
//fflush(stdin);

//ex. 5
void  buscarPalavra(char *txt,char *palavra,int pos[],int *tam)
{
    int i,j;
    int tam1=size(txt);
    int tam2=size(palavra);
    *tam=0;
    for (i=0;i<tam1;i++)
    {
        for (j=0;j<tam2 && palavra[j]==txt[i+j];j++)
        {}
        if (j==tam2)
        {
            pos[*tam]=i;
            (*tam)++;
        }
    }
}

int main()
{
    int pos[MAX_S];
    int tam,i;
    buscarPalavra("ola liana laiana","la",pos,&tam);

    printf("Pos: [ ");
    for (i=0;i<tam;i++)
    {
        printf("%i ",pos[i]);
    }
    printf("]\n");

    return 0;
}

----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preencheVet(int *vet,int *quantV)
{
    srand(time(NULL));
    //srand(NULL);
    *quantV = 5;
    int i=0;
    for (;i<*quantV;i++)
    {
        //vet[0]=rand()%100;
        *vet=rand()%100;
        vet++;
    }
}

void imprimir(int *vet,int quantV)
{
    int i;
    printf("Vetor: [");
    for (i=0;i<quantV;i++)
    {
        printf(" %2i",*vet);
        vet++;
    }
    printf("]\n");
}

int main()
{
    int vet[40];
    int quantV;

    preencheVet(vet,&quantV);
    imprimir(vet,quantV);
    return 0;
}


--------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preencheVet(int *vet,int *quantV)
{
    srand(time(NULL));
    //srand(NULL);
    *quantV = 5;
    int i=0;
    for (;i<*quantV;i++)
    {
        //vet[0]=rand()%100;
        *vet=rand()%100;
        vet++;
    }
}

void imprimir(int *vet,int quantV)
{
    int i;
    printf("Vetor: [");
    for (i=0;i<quantV;i++)
    {
        printf(" %2i",*vet);
        vet++;
    }
    printf("]\n");
}

void imprimir2(int *vet,int quantV)
{
    int i;
    printf("Vetor: [");
    for (i=0;i<quantV;i++)
    {
        printf(" %2i",*(vet+i));
    }
    printf("]\n");
}

int main()
{
    int vetor[40];
    int quantV;

    preencheVet(vetor,&quantV);
    imprimir(vetor,quantV);

    imprimir2(vetor,quantV);
    return 0;
}

-----------------------------


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preencheVet(int *vet,int *quantV)
{
    srand(time(NULL));
    //srand(NULL);
    *quantV = 5;
    int i=0;
    for (;i<*quantV;i++)
    {
        //vet[0]=rand()%100;
        *vet=rand()%100;
        vet++;
    }
}

void imprimir(int *vet,int quantV)
{
    int i;
    printf("Vetor: [");
    for (i=0;i<quantV;i++)
    {
        printf(" %2i",*vet);
        vet++;
    }
    printf("]\n");
}

void imprimir2(int *vet,int quantV)
{
    int i;
    printf("Vetor: [");
    for (i=0;i<quantV;i++)
    {
        printf(" %2i",*(vet+i));
    }
    printf("]\n");
}

void soma(int *vet,int quantV,int valor)
{
    int i;
    for (i=0;i<quantV;i++)
    {
        (*(vet+i))+=valor;
    }
}

void sub(int *vet,int quantV,int valor)
{
    int i;
    for (i=0;i<quantV;i++)
    {
        (*(vet+i))-=valor;
    }
}

void executa(int *vet,int quantV,int valor,void (*func)(int *,int,int))
{
    func(vet,quantV,valor);
}

int main()
{
    int vetor[40];
    int quantV;

    preencheVet(vetor,&quantV);
    imprimir(vetor,quantV);

    executa(vetor,quantV,2,sub);
    imprimir2(vetor,quantV);

    executa(vetor,quantV,10,soma);
    imprimir2(vetor,quantV);

    return 0;


------------------------------------


#include <stdio.h>

#define MAX 250

typedef struct{
    int nivel;
    char nome[50];
    char tipo[50];
}Pokemon;

void print(Pokemon pokedex[],int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        printf("Nome:%s - Tipo: %s - Nivel: %i\n",pokedex[i].nome,pokedex[i].tipo,pokedex[i].nivel);
    }
}

void lerPokemons(char *filename,Pokemon pokedex[],int *index)
{
    FILE *arq = fopen(filename,"r");
    if (arq==NULL)
    {
        fprintf(stderr,"Erro ao abrir o arquivo pokemon.txt\n");
        return;
    }

    while (!feof(arq))
    {
        fscanf(arq,"%[^\n]\n",pokedex[*index].nome);
        fscanf(arq,"%i\n",&pokedex[*index].nivel);
        fscanf(arq,"%[^\n]\n",pokedex[*index].tipo);


        (*index)++;
    }
    fclose(arq);
}

void separaPokemons(Pokemon pokedex[],int index)
{
    FILE *normal;
    FILE *fogo;
    FILE *agua;
    FILE *grama;

    int i;

    normal = fopen("pokemonNormal.txt","w");
    fogo = fopen("pokemonFogo.txt","w");
    agua = fopen("pokemonAgua.txt","w");
    grama = fopen("pokemonGrama.txt","w");

    for (i=0;i<index;i++)
    {
        if (pokedex[i].nivel>=50)
        {
            switch (pokedex[i].tipo[0])
            {
                case 'n':{
                    fprintf(normal,"%s\n%i\n%s\n",pokedex[i].nome,pokedex[i].nivel,pokedex[i].tipo);
                    break;
                }
                case 'f':{
                    fprintf(fogo,"%s\n%i\n%s\n",pokedex[i].nome,pokedex[i].nivel,pokedex[i].tipo);
                    break;
                }
                case 'A':
                case 'a':{
                    fprintf(agua,"%s\n%i\n%s\n",pokedex[i].nome,pokedex[i].nivel,pokedex[i].tipo);
                    break;
                }
                case 'G':
                case 'g':{
                    fprintf(grama,"%s\n%i\n%s\n",pokedex[i].nome,pokedex[i].nivel,pokedex[i].tipo);
                    break;
                }
            }

        }
    }

    fclose(normal);
    fclose(fogo);
    fclose(agua);
    fclose(grama);
}

int main()
{
    int index = 0;

    Pokemon pokedex[MAX];

    lerPokemons("pokemon.txt",pokedex,&index);

    print(pokedex,index);

    separaPokemons(pokedex,index);

    return 0;

}


-------------------------REGISTROS-----------------


Elaborar um programa escolar que armazene o nome e as notas bimestrais de 20 alunos de um determinado curso, definir a estrutura de registro apropriada, o diagrama de blocos e a codificação de um programa que, por meio de um menu de opções, execute as seguintes etapas:
i. Cadastrar os 20 registros (após o cadastro dos 20 registros, classificar imediatamente a tabela de dados pelo campo nome).
ii. Pesquisar os 20 registros, de cada vez, pelo campo nome (usar o método de pesquisa binária; nessa pesquisa, o programa deve também apresentar a média do aluno e as mensagens: "Aprovado", caso sua média seja maior ou igual a 5, ou "Reprovado" para média abaixo de 5).
iii. Apresentar todos os registros, médias e a mensagem de aprovação ou reprovação. iv. Sair do programa de cadastro.
(c) Elaborar um programa que efetue o gerenciamento dos dados de dez registros de uma agenda que contenha nomes, endereços e telefones, defina a estrutura de registro apropriada, o di- agrama de blocos e a codificação de um programa que, por meio de um menu de opções, execute as seguintes etapas:
i. Cadastrar os dez registros.
1
ii. Pesquisar um registro de cada vez pelo campo nome (usar o método sequencial). iii. Classificar por ordem de nome os registros cadastrados.
iv. Apresentar todos os registros.
v. Sair do programa de cadastro.
2





#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct curso
{
    char nome[50];
    float nota[4];
}Curso;

void adicionar_aluno(Curso curso[], int indice)
{
    printf("\nNome: ");
    scanf("%[^\n]s", curso[indice].nome);


    int i;

    for(i=0; i<4;i++){
        printf("notas dos 4 bimestres: ");
        scanf("%f", curso[i].nota[i]);
    }
}

void pesquisar(Curso curso[], int indice)
{
    char nome[100];

    printf("digite o nome que deseja pesquisar: \n");
    scanf("%[^\n]s", nome);

    int i;

    for(i=0; i<indice;i++)
    {
        if(strcmp(curso[i].nome, nome)==0){
            printf("Aluno encontrado: %s", curso[i].nome);
            print("\nnotas\n");

            int j;

            for(j=0; j<4;j++){
                printf("notas: %.2f\n", curso[i].nota[j]);
            }

        }
    }
}

int main()
{
    Curso curso[20];
    int op;
    int indice=0;
    while(op!=5)
    {
        printf("1-adicionar aluno\n");
        printf("2-classificar alunos pelo nome\n");
        printf("3-pesquisar aluno\n");
        printf("4-apresentar todos os registros\n");
        scanf("%d", &op);

        if(op==1){
            adicionar_aluno(curso, indice);
            indice++;
        }

        if(op==2){

        }
    }

}

---------------------------------------------



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct curso
{
    char nome[50];
    float nota[4];
    float media;
} Curso;

void cadastrar_registros(Curso curso[]);
void classificar_por_nome(Curso curso[]);
void pesquisar_por_nome(Curso curso[]);
void apresentar_registros(Curso curso[]);
void calcular_media(Curso *curso);

int main()
{
    Curso curso[20];
    int op;
    
    do
    {
        printf("\nMENU DE OPCOES:\n");
        printf("1 - Cadastrar 20 registros\n");
        printf("2 - Pesquisar registro por nome\n");
        printf("3 - Apresentar todos os registros\n");
        printf("4 - Sair do programa\n");
        scanf("%d", &op);
        
        switch(op)
        {
            case 1:
                cadastrar_registros(curso);
                classificar_por_nome(curso);
                printf("Registros cadastrados e classificados por nome com sucesso.\n");
                break;
            case 2:
                pesquisar_por_nome(curso);
                break;
            case 3:
                apresentar_registros(curso);
                break;
            case 4:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while(op != 4);
    
    return 0;
}

void cadastrar_registros(Curso curso[])
{
    int i, j;
    
    for(i=0; i<20; i++)
    {
        printf("\nCadastro do aluno %d\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]s", curso[i].nome);
        
        for(j=0; j<4; j++)
        {
            printf("Nota do bimestre %d: ", j+1);
            scanf("%f", &curso[i].nota[j]);
        }
        
        calcular_media(&curso[i]);
    }
}

void classificar_por_nome(Curso curso[])
{
    int i, j;
    Curso temp;
    
    for(i=0; i<19; i++)
    {
        for(j=i+1; j<20; j++)
        {
            if(strcmp(curso[i].nome, curso[j].nome) > 0)
            {
                temp = curso[i];
                curso[i] = curso[j];
                curso[j] = temp;
            }
        }
    }
}

void pesquisar_por_nome(Curso curso[])
{
    char nome_pesquisa[50];
    int inicio = 0, fim = 19, meio, encontrado = 0;
    
    printf("\nDigite o nome a ser pesquisado: ");
    scanf(" %[^\n]s", nome_pesquisa);
    
    while(inicio <= fim && !encontrado)
    {
        meio = (inicio + fim) / 2;
        if(strcmp(curso[meio].nome, nome_pesquisa) == 0)
        {
            encontrado = 1;
            printf("\nDados do aluno encontrado:\n");
            printf("Nome: %s\n", curso[meio].nome);
            printf("Notas: %.2f, %.2f, %.2f, %.2f\n", curso[meio].nota[0], curso[meio].nota[1], curso[meio].nota[



------------------------------


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct agenda
{
    char nome[50];
    char endereco[100];
    char telefone[20];
} Agenda;

void cadastrar_registro(Agenda *agenda);
void pesquisar_registro(Agenda *agenda);
void classificar_registros(Agenda *agenda);
void apresentar_registros(Agenda *agenda);

int main()
{
    Agenda agenda[10];
    int op;

    while(op != 5)
    {
        printf("\nMENU DE OPCOES\n");
        printf("1 - Cadastrar registro\n");
        printf("2 - Pesquisar registro\n");
        printf("3 - Classificar registros\n");
        printf("4 - Apresentar todos os registros\n");
        printf("5 - Sair do programa\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                cadastrar_registro(agenda);
                break;
            case 2:
                pesquisar_registro(agenda);
                break;
            case 3:
                classificar_registros(agenda);
                break;
            case 4:
                apresentar_registros(agenda);
                break;
            case 5:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}

void cadastrar_registro(Agenda *agenda)
{
    printf("\nCADASTRO DE REGISTRO\n");

    int i;

    for(i = 0; i < 10; i++)
    {
        if(strlen(agenda[i].nome) == 0)
        {
            printf("\nDigite o nome: ");
            scanf("%s", agenda[i].nome);

            printf("Digite o endereco: ");
            scanf("%s", agenda[i].endereco);

            printf("Digite o telefone: ");
            scanf("%s", agenda[i].telefone);

            printf("\nRegistro cadastrado com sucesso!\n");
            break;
        }
    }

    if(i == 10)
    {
        printf("\nAgenda lotada! Impossivel cadastrar novo registro.\n");
    }
}

void pesquisar_registro(Agenda *agenda)
{
    printf("\nPESQUISA DE REGISTRO\n");

    char nome[50];
    int i, encontrado = 0;

    printf("\nDigite o nome do registro que deseja pesquisar: ");
    scanf("%s", nome);

    for(i = 0; i < 10; i++)
    {
        if(strcmp(agenda[i].nome, nome) == 0)
        {
            printf("\nRegistro encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Endereco: %s\n", agenda[i].endereco);
            printf("
-----------------------------------------------------------------------------------------------------



-----------------------------------------------



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _file
{
    char *nome;
    char dados[256];
    struct _file *prox;
    struct _file *ant;
}File;
typedef struct _folder
{
    File *file;
    char *nome_folder;
    struct _folder *pai;
    struct _folder *subfolder;
    struct _folder *prox;
    struct _folder *ant;
}Folder;
typedef struct
{
    Folder *Root;
    Folder *atual;
}Pivo;
typedef struct _pilha
{
    File *file;
    struct _pilha *prox;
    struct _pilha *ant;
}Pilha;
Pilha *cria_pilha()
{
    Pilha *p = malloc(sizeof(Pilha));
    p->prox = NULL;
    p->ant = NULL;
    return p;
}
void empilhar(Pilha **pilha, File *file)
{
    Pilha *no = malloc(sizeof(Pilha));
    if(no)
    {
        no->file = file;
        no->prox = *pilha;
        no->ant = NULL;
        if(*pilha)
        {
            (*pilha)->ant = no;
        }
        *pilha = no;
    }
}
Pilha *desempilhar(Pilha **pilha)
{
    Pilha *post = (*pilha)->prox;
    Pilha *ant = (*pilha)->prox->ant;
    if(*pilha)
    {
        *pilha = post;
        return ant;
    }
}
void esvaziar_pilha(Pilha *pilha)
{
    Pilha *excluido = NULL;
    if (pilha->prox!=NULL)
    {
        esvaziar_pilha(pilha->prox);
        excluido = (desempilhar(&pilha));
        printf("%s\n", excluido->file->nome);
        free(excluido);
        excluido = NULL;
    }
}
Pivo *criarPivo()
{
    Pivo *pivo = (Pivo*) malloc(sizeof(Pivo));
    pivo->Root = NULL;
    pivo->atual = NULL;
    return pivo;
}
File *criarFile(char *nome)
{
    File *new_file = (File*) malloc(sizeof(File));
    new_file->nome = nome;
    new_file->prox = NULL;
    new_file->ant = NULL;
    return new_file;
}
Folder *criarFolder(char *nome)
{
    Folder *new_folder = (Folder*) malloc(sizeof(Folder));
    new_folder->ant = NULL;
    new_folder->prox = NULL;
    new_folder->nome_folder = nome;
    new_folder->subfolder = NULL;
    new_folder->file = NULL;
    new_folder->pai = NULL;
    return new_folder;
}
void iniciar(Pivo **pivo)
{
    Folder *root = criarFolder("Root");
    root->pai = root;
    (*pivo)->Root = root;
    (*pivo)->atual = root;
}
void newFile(Folder *folder,char *nome)
{
    File *nFile = criarFile(nome);
    if(folder->file == NULL)
    {
        folder->file = nFile;
    }
    else
    {
        File *aux = folder->file;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        nFile->ant = aux;
        aux->prox = nFile;
    }
    return;
}
File *del(Folder **folder, char *nome)
{
    File *aux = (*folder)->file;
    if(aux == NULL)
    {
        return NULL;
    }
    else if(aux->nome == nome)
    {
        (*folder)->file = aux->prox;
    }
    else
    {
        while(aux->prox != NULL && aux->nome != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome != nome)
        {
            return NULL;
        }
        else if(aux->prox == NULL)
        {
            aux->ant->prox = NULL;
        }
        else if(aux!=NULL)
        {
            aux->ant->prox = aux->prox;
        }
        return aux;
    }
}
int ls(Folder *raiz, char *nome)
{
    Folder *aux = raiz;
    File *auxL = NULL;
    if(aux->nome_folder == nome)
    {
        auxL = aux->file;
        printf("SubPastas\n");
        while(aux != NULL)
        {
            printf("%3s%s\n", " ", aux->nome_folder);
            aux = aux->prox;
        }
        printf("Arquivos\n");
        while(auxL != NULL)
        {
            printf("%3s%s\n"," ", auxL->nome);
            auxL = auxL->prox;
        }
    }
    else
    {
        aux = raiz->subfolder;
        while(aux->prox != NULL && aux->nome_folder != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome_folder != nome)
        {
            puts("Nada");
            return -1;
        }
        else
        {
            auxL = aux->file;
            Folder *auxP = aux->subfolder;
            printf("SubPastas\n");
            while(auxP != NULL)
            {
                printf("%3s%s\n", " ", auxP->nome_folder);
                auxP = auxP->prox;
            }
            printf("Arquivos\n");
            while(auxL != NULL)
            {
                printf("%3s%s\n"," ", auxL->nome);
                auxL = auxL->prox;
            }
        }
    }

}
void mk(Folder **atual, char *nome)
{
    Folder *newFolder = criarFolder(nome);
    newFolder->pai = (*atual);
    Folder *atual_sub = *atual;
    if(atual_sub->subfolder == NULL)
    {
        atual_sub->subfolder = newFolder;
    }
    else
    {
        while(atual_sub->prox != NULL)
        {
            atual_sub = atual_sub->prox;
        }
        newFolder->ant = atual_sub;
        atual_sub->prox->subfolder = newFolder;
    }
}
int cd(Folder **pasta_atual, char *nome)
{
    if((*pasta_atual)->nome_folder == nome)
    {
        return 1;
    }
    else
    {
        Folder *aux = (*pasta_atual)->subfolder;

        while(aux->prox != NULL && aux->nome_folder != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome_folder != nome)
        {
            return -1;
        }
        else
        {
            *pasta_atual = aux;
            return 0;
        }
    }
}
int edit(Folder **atual, char *nome) //FOLDER
{
    File *aux = (*atual)->file;
    if(aux == NULL)
    {
        return -1;
    }
    else if(aux->nome == nome)
    {
        printf("Digite o conteudo do arquivo:\n");
        gets(aux->dados);
        return 0;
    }
    else
    {

        while(aux->prox != NULL && aux->nome != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome != nome)
        {
            return -1;
        }
        else
        {
            printf("Digite o conteudo do arquivo:\n");
            gets(aux->dados);
            return 0;
        }
    }
}
int view(Folder *atual, char *nome)
{
    if(atual->file == NULL)
    {
        return -1;
    }
    else if(atual->file->nome == nome)
    {
        printf("Conteudo do Arquivo (%s)\n", atual->file->nome);
        printf("%s\n", atual->file->dados);
    }
    else
    {
        File *aux = atual->file;

        while(aux->prox != NULL && aux->nome != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome != nome)
        {
            return -1;
        }
        else
        {
            printf("Conteudo do Arquivo (%s)\n", aux->nome);
            printf("%s\n", aux->dados);
        }
    }
}
Folder *rm(Folder *raiz, char *nome)
{
    Folder *aux = raiz->subfolder;
    if(aux == NULL)
    {
        return NULL;
    }
    else if(aux->nome_folder == nome)
    {
        aux = aux->prox;
    }
    else
    {
        while(aux->prox != NULL && aux->nome_folder != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome_folder != nome)
        {
            return NULL;
        }
        else if(aux->prox == NULL)
        {
            aux->ant->prox = NULL;
        }
        else if(aux!=NULL)
        {
            aux->ant->prox = aux->prox;
        }
        return aux;
    }
}
int find(Pilha **pilha, Folder *raiz, char *palavra)
{
    Folder *aux = raiz;

    if(aux == NULL)
    {

        printf("Arquivos com a palavra (%s)\n", palavra);
        esvaziar_pilha((*pilha));
    }
    else
    {
        File *auxL = aux->file;
        while(auxL->prox != NULL && strstr(auxL->dados, palavra) == NULL)
        {
            auxL = auxL->prox;
        }
        if(strstr(auxL->dados, palavra) == NULL)
        {
            return -1;
        }
        else
        {
            empilhar(pilha, auxL);
        }
        find(pilha, aux->prox, palavra);
    }
}
int cd__(Folder **atual)
{
    (*atual) = (*atual)->pai;
}
int main()
{
    char *controle;
    Pilha *pilha = cria_pilha();
    Pivo *pivo = criarPivo();
    File *retorno = NULL;
    iniciar(&pivo);
    newFile(pivo->atual, "Arquivao");
    mk(&(pivo)->atual, "Teste2");
    puts("sai");
    printf("Nome pasta:%s\nNome subpasta:%s\n", pivo->atual->nome_folder, pivo->atual->subfolder->nome_folder);
    //edit(&(pivo)->atual, "Arquivao");
    //view(pivo->atual, "Arquivao");
    cd(&(pivo)->atual, "Teste2");
    printf("Nome pasta:%s\n", pivo->atual->nome_folder);
    cd__(&(pivo)->atual);
    printf("Nome pasta:%s\n", pivo->atual->nome_folder);
    newFile(pivo->atual, "Arquivs");
    mk(&(pivo)->atual, "Teste3");
    printf("Nome pasta:%s\nNome subpasta:%s\n", pivo->atual->nome_folder, pivo->atual->subfolder->nome_folder);
    printf("Arquivo:%s\n", pivo->atual->file->nome);
    ls(pivo->Root, "Teste2");
    edit(&(pivo)->atual, "Arquivs");
    view(pivo->atual, "Arquivs");
    find(&pilha, pivo->Root->subfolder, "ser");

    return 0;

}



/*
            Código escrito por Wagner Gaspar
            Agosto de 2021

            Aula 254: Lista Simplesmente Encadeada
            Gerar uma lista C com os elementos das Listas A e B
/*

typedef struct no{
    int valor;
    struct no *proximo;
}No;

// procedimento para inserir no início
void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL)
            *lista = novo;
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // é o primeiro?
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // a lista está vazia?
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } // é o menor?
        else if(novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

No* remover(No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    return remover;
}

No* buscar(No **lista, int num){
    No *aux, *no = NULL;

    aux = *lista;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    return no;
}

void copiar_lista(No **l, No **C){
    No *aux = *l;
    while(aux){
        inserir_no_inicio(C, aux->valor);
        aux = aux->proximo;
    }
}

void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){

    int opcao, valor, anterior;
    No *removido, *A, *B, *C;
    A = NULL;
    B = NULL;
    C = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7 - Buscar\n\t8 - Copiar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1: // insere nas listas A e B
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&A, valor);
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&B, valor);
            break;
        case 2: // insere apenas na lista A
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&A, valor);
            break;
        case 3: // insere apenas na lista B
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&B, valor, anterior);
            break;
        case 4: // insere apenas na lista A
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&A, valor);
            break;
        case 5:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&C, valor);
            if(removido){
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");
            break;
        case 6:
            printf("\nLista A:\n");
            imprimir(A);
            printf("\nLista B:\n");
            imprimir(B);
            printf("\nLista C:\n");
            imprimir(C);
            break;
        case 7:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&C, valor);
            if(removido)
                printf("Elemento encontrado: %d\n", removido->valor);
            else
                printf("Elemento nao encontrado!\n");
            break;
        case 8:
            copiar_lista(&A, &C);
            copiar_lista(&B, &C);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}



-------------------------------------------------------------------------------------------




Conversa aberta. Uma mensagem lida.

Pular para o conteúdo
Como usar o Gmail com leitores de tela
12 de 6.046
Sub Lab 2.pdf
Caixa de entrada

GUSTAVO BOM <bomgustavo10@gmail.com>
Anexos
seg., 24 de abr., 21:52 (há 16 horas)
para mim








Enviado do meu iPhone
2
 anexos
  •  Anexos verificados pelo Gmail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _file
{
    char *nome;
    char dados[256];
    struct _file *prox;
    struct _file *ant;
}File;
typedef struct _folder
{
    File *file;
    char *nome_folder;
    struct _folder *pai;
    struct _folder *subfolder;
    struct _folder *prox;
    struct _folder *ant;
}Folder;
typedef struct
{
    Folder *Root;
    Folder *atual;
}Pivo;
typedef struct _pilha
{
    File *file;
    struct _pilha *prox;
    struct _pilha *ant;
}Pilha;
Pilha *cria_pilha()
{
    Pilha *p = malloc(sizeof(Pilha));
    p->prox = NULL;
    p->ant = NULL;
    return p;
}
void empilhar(Pilha **pilha, File *file)
{
    Pilha *no = malloc(sizeof(Pilha));
    if(no)
    {
        no->file = file;
        no->prox = *pilha;
        no->ant = NULL;
        if(*pilha)
        {
            (*pilha)->ant = no;
        }
        *pilha = no;
    }
}
Pilha *desempilhar(Pilha **pilha)
{
    Pilha *post = (*pilha)->prox;
    Pilha *ant = (*pilha)->prox->ant;
    if(*pilha)
    {
        *pilha = post;
        return ant;
    }
}
void esvaziar_pilha(Pilha *pilha)
{
    Pilha *excluido = NULL;
    if (pilha->prox!=NULL)
    {
        esvaziar_pilha(pilha->prox);
        excluido = (desempilhar(&pilha));
        printf("%s\n", excluido->file->nome);
        free(excluido);
        excluido = NULL;
    }
}
Pivo *criarPivo()
{
    Pivo *pivo = (Pivo*) malloc(sizeof(Pivo));
    pivo->Root = NULL;
    pivo->atual = NULL;
    return pivo;
}
File *criarFile(char *nome)
{
    File *new_file = (File*) malloc(sizeof(File));
    new_file->nome = nome;
    new_file->prox = NULL;
    new_file->ant = NULL;
    return new_file;
}
Folder *criarFolder(char *nome)
{
    Folder *new_folder = (Folder*) malloc(sizeof(Folder));
    new_folder->ant = NULL;
    new_folder->prox = NULL;
    new_folder->nome_folder = nome;
    new_folder->subfolder = NULL;
    new_folder->file = NULL;
    new_folder->pai = NULL;
    return new_folder;
}
void iniciar(Pivo **pivo)
{
    Folder *root = criarFolder("Root");
    root->pai = root;
    (*pivo)->Root = root;
    (*pivo)->atual = root;
}
void newFile(Folder *folder,char *nome)
{
    File *nFile = criarFile(nome);
    if(folder->file == NULL)
    {
        folder->file = nFile;
    }
    else
    {
        File *aux = folder->file;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        nFile->ant = aux;
        aux->prox = nFile;
    }
    return;
}
File *del(Folder **folder, char *nome)
{
    File *aux = (*folder)->file;
    if(aux == NULL)
    {
        return NULL;
    }
    else if(aux->nome == nome)
    {
        (*folder)->file = aux->prox;
    }
    else
    {
        while(aux->prox != NULL && aux->nome != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome != nome)
        {
            return NULL;
        }
        else if(aux->prox == NULL)
        {
            aux->ant->prox = NULL;
        }
        else if(aux!=NULL)
        {
            aux->ant->prox = aux->prox;
        }
        return aux;
    }
}
int ls(Folder *raiz, char *nome)
{
    Folder *aux = raiz;
    File *auxL = NULL;
    if(aux->nome_folder == nome)
    {
        auxL = aux->file;
        printf("SubPastas\n");
        while(aux != NULL)
        {
            printf("%3s%s\n", " ", aux->nome_folder);
            aux = aux->prox;
        }
        printf("Arquivos\n");
        while(auxL != NULL)
        {
            printf("%3s%s\n"," ", auxL->nome);
            auxL = auxL->prox;
        }
    }
    else
    {
        aux = raiz->subfolder;
        while(aux->prox != NULL && aux->nome_folder != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome_folder != nome)
        {
            puts("Nada");
            return -1;
        }
        else
        {
            auxL = aux->file;
            Folder *auxP = aux->subfolder;
            printf("SubPastas\n");
            while(auxP != NULL)
            {
                printf("%3s%s\n", " ", auxP->nome_folder);
                auxP = auxP->prox;
            }
            printf("Arquivos\n");
            while(auxL != NULL)
            {
                printf("%3s%s\n"," ", auxL->nome);
                auxL = auxL->prox;
            }
        }
    }

}
void mk(Folder **atual, char *nome)
{
    Folder *newFolder = criarFolder(nome);
    newFolder->pai = (*atual);
    Folder *atual_sub = *atual;
    if(atual_sub->subfolder == NULL)
    {
        atual_sub->subfolder = newFolder;
    }
    else
    {
        while(atual_sub->prox != NULL)
        {
            atual_sub = atual_sub->prox;
        }
        newFolder->ant = atual_sub;
        atual_sub->prox->subfolder = newFolder;
    }
}
int cd(Folder **pasta_atual, char *nome)
{
    if((*pasta_atual)->nome_folder == nome)
    {
        return 1;
    }
    else
    {
        Folder *aux = (*pasta_atual)->subfolder;

        while(aux->prox != NULL && aux->nome_folder != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome_folder != nome)
        {
            return -1;
        }
        else
        {
            *pasta_atual = aux;
            return 0;
        }
    }
}
int edit(Folder **atual, char *nome)
{
    File *aux = (*atual)->file;
    if(aux == NULL)
    {
        return -1;
    }
    else if(aux->nome == nome)
    {
        printf("Digite o conteudo do arquivo:\n");
        gets(aux->dados);
        return 0;
    }
    else
    {

        while(aux->prox != NULL && aux->nome != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome != nome)
        {
            return -1;
        }
        else
        {
            printf("Digite o conteudo do arquivo:\n");
            gets(aux->dados);
            return 0;
        }
    }
}
int view(Folder *atual, char *nome)
{
    if(atual->file == NULL)
    {
        return -1;
    }
    else if(atual->file->nome == nome)
    {
        printf("Conteudo do Arquivo (%s)\n", atual->file->nome);
        printf("%s\n", atual->file->dados);
    }
    else
    {
        File *aux = atual->file;

        while(aux->prox != NULL && aux->nome != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome != nome)
        {
            return -1;
        }
        else
        {
            printf("Conteudo do Arquivo (%s)\n", aux->nome);
            printf("%s\n", aux->dados);
        }
    }
}
Folder *rm(Folder *raiz, char *nome)
{
    Folder *aux = raiz->subfolder;
    if(aux == NULL)
    {
        return NULL;
    }
    else if(aux->nome_folder == nome)
    {
        aux = aux->prox;
    }
    else
    {
        while(aux->prox != NULL && aux->nome_folder != nome)
        {
            aux = aux->prox;
        }
        if(aux->nome_folder != nome)
        {
            return NULL;
        }
        else if(aux->prox == NULL)
        {
            aux->ant->prox = NULL;
        }
        else if(aux!=NULL)
        {
            aux->ant->prox = aux->prox;
        }
        return aux;
    }
}
int find(Pilha **pilha, Folder *raiz, char *palavra)
{
    Folder *aux = raiz;

    if(aux == NULL)
    {

        printf("Arquivos com a palavra (%s)\n", palavra);
        esvaziar_pilha((*pilha));
    }
    else
    {
        File *auxL = aux->file;
        while(auxL->prox != NULL && strstr(auxL->dados, palavra) == NULL)
        {
            auxL = auxL->prox;
        }
        if(strstr(auxL->dados, palavra) == NULL)
        {
            return -1;
        }
        else
        {
            empilhar(pilha, auxL);
        }
        find(pilha, aux->prox, palavra);
    }
}
int cd__(Folder **atual)
{
    (*atual) = (*atual)->pai;
}
int main()
{
    char *controle;
    Pilha *pilha = cria_pilha();
    Pivo *pivo = criarPivo();
    File *retorno = NULL;
    iniciar(&pivo);
    newFile(pivo->atual, "Arquivao");
    mk(&(pivo)->atual, "Teste2");
    puts("sai");
    printf("Nome pasta:%s\nNome subpasta:%s\n", pivo->atual->nome_folder, pivo->atual->subfolder->nome_folder);
    //edit(&(pivo)->atual, "Arquivao");
    //view(pivo->atual, "Arquivao");
    cd(&(pivo)->atual, "Teste2");
    printf("Nome pasta:%s\n", pivo->atual->nome_folder);
    cd__(&(pivo)->atual);
    printf("Nome pasta:%s\n", pivo->atual->nome_folder);
    newFile(pivo->atual, "Arquivs");
    mk(&(pivo)->atual, "Teste3");
    printf("Nome pasta:%s\nNome subpasta:%s\n", pivo->atual->nome_folder, pivo->atual->subfolder->nome_folder);
    printf("Arquivo:%s\n", pivo->atual->file->nome);
    ls(pivo->Root, "Teste2");
    edit(&(pivo)->atual, "Arquivs");
    view(pivo->atual, "Arquivs");
    find(&pilha, pivo->Root->subfolder, "ser");

    return 0;

}
Sub lab 2.c
Exibindo Sub lab 2.c.


-----------------------------------------------------


void imprimir_lista_inverso (struct no *aux)
{
    if(aux == NULL)
        return;
    imprimir_lista_inverso(aux->prox);
    printf ("Dado = %d\n", aux -> num);
}


-----------------------------------------------------INTERCALAR---------------------



insira o código aqui
#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA{
    int dado;
    struct LISTA *prox;
} lista;

typedef struct LISTA2{
    int dado;
    struct LISTA2 *prox;
} lista2;

lista *insere(lista *p, int valor){ 
    lista *novo;
    novo=(lista*)malloc(sizeof(lista));
    novo->dado = valor;
    novo->prox = p;
    return novo;        
}

void imprime(lista *l){
    lista *p = l;
    for(p = l; p != NULL; p=p->prox){
        printf("%d-",p->dado);
    }
}

lista* intercala (lista* l, lista2* l2){    
    lista *li = (lista*)malloc(sizeof(lista));
    lista *p1;
    lista2 *p2;

    for(p1 =l, p2 =l2; p1!= NULL && p2!=NULL; p1 =p1->prox, p2=p2->prox){
        li->dado = p1->dado;
        li->prox = p1->prox;
        li->dado = p2->dado;
        li->prox = p2->prox;
    }
    return li;
}

main(){     
    lista *l;
    lista2 *l2;
    l  = NULL;
    l2 = NULL;

    l = insere(l, 1);
    l = insere(l, 2);
    l = insere(l, 3);
    imprime(l);
    printf("\n");
    l2 = insere(l2, 4);
    l2 = insere(l2, 5);
    l2 = insere(l2, 6);
    imprime(l2);
    printf("\n");
    //concatena(l,l2);
    //imprime(l);
    l =intercala (l,l2);
    imprime(l);
}


--------------------------------------------------inverter lista encadeada----------------


void reverseR(NODE **head) {

    /* Tratar lista vazia */
    if (*head == NULL) return;

    /* Atribuir um ponteiro para o nó atual
       e outro ponteiro para o restante da lista */
    NODE *curr;
    NODE *rest;
    curr = *head;
    rest = curr->next;

    /* Retornar ao chegar no final da lista */
    if (rest == NULL) return;

    /* Chamar a recursão até atingir o final da lista */
    reverseR(&rest);

    /* Inverter os nós e acertar a cabeça da lista */
    curr->next->next = curr;
    curr->next = NULL;
    *head = rest;
}


---------------------------------------



Compartilhar
Melhore esta resposta
Seguir
editada 11/04/2018 às 0:23
respondida 11/04/2018 às 0:16
DarkGV's user avatar
DarkGV
7311 medalhas de ouro11 medalhas de prata77 medalhas de bronze
Troquei de lugar o return 1 e pus depois da { do while e tirei o else, porém, a saída ta diferente do esperado. Está com a saída 1 1 1 1 e tem que retornar 1 0 0 0 segundo o que está no exercício. – 
Maurício Z.B
 11/04/2018 às 0:20 
2
while com return no if e no else ? O seu else não seria antes fora do while ? E o =! não seria != ? – 
Isac
 11/04/2018 às 0:24
1
o que o @Isac disse é verdade, =! não existe... ou é == ! ou é != Na edição meti a minha forma de testar se 2 listas são iguais. Se quiser testar a minha forma a ver se está bem faça-o. Caso esteja correta leia e perceba. Alguma coisa mande mensagem para mim que eu ajudo. Eu não tenho muita experiência com listas, mas farei o meu melhor para o ajudar. – 
DarkGV
 11/04/2018 às 0:25 
Obrigado pela observação pessoal, mas continua dando erro. Será que falta alguma condição? Vou editar o código ai em cima – 
Maurício Z.B
 11/04/2018 às 0:32 
1
@YODA a primeira iteração (dentro do while) vai dar 1 devido ao else – 
DarkGV
 11/04/2018 às 0:35 
Mostrar mais 2 comentários


1


#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct No
{
    int nConteudo;
    struct No *prox;
}TNo;
 

typedef TNo* TLista;

void liberar_memoria(TLista p);

void verificaPar(TLista p1, TLista p2);

void mostraLista(TLista p1, TLista p2);
 
int main(void)
{
    TLista pNo1 = NULL;
    TLista pNo2 = NULL;
    TLista pNo3 = NULL;
    
    TLista pNo4 = NULL;
    TLista pNo5 = NULL;
    TLista pNo6 = NULL;
     
    
    pNo1 = (TLista) malloc(sizeof(TLista));
    pNo1->nConteudo = 110;
     
    pNo2 = (TLista) malloc(sizeof(TLista));
    pNo2->nConteudo = 210;
     
    pNo3 = (TLista) malloc(sizeof(TLista));
    pNo3->nConteudo = 310;
    
    
    pNo4 = (TLista) malloc(sizeof(TLista));
    pNo4->nConteudo = 110;
     
    pNo5 = (TLista) malloc(sizeof(TLista));
    pNo5->nConteudo = 210;
     
    pNo6 = (TLista) malloc(sizeof(TLista));
    pNo6->nConteudo = 310;
    
    pNo1->prox = pNo2;
    pNo2->prox = pNo3;  
    pNo3->prox = NULL;
    
    pNo4->prox = pNo5;
    pNo5->prox = pNo6;  
    pNo6->prox = NULL;
     
    mostraLista(pNo1,pNo4);
     
    verificaPar(pNo1, pNo4);
    
    liberar_memoria(pNo1);
    liberar_memoria(pNo4);
  
    return 0;
}

void liberar_memoria(TLista p)
{
    TLista atual = p;

    while (atual != NULL)
    {
        TLista proximo = atual->prox;

        free(atual);

        atual = proximo;
    }
}

void mostraLista(TLista p1, TLista p2)
{
    TLista i,j;
    printf("\nMostrando a lista:\n"); 

    if((p1)&&(p2))

    for (i=p1,j=p2; p1!=NULL;p2=p2->prox,p1=p1->prox)
    {
        printf("\n%d\t", i->nConteudo); printf("- %d\n", j->nConteudo);

        i=i->prox;  j=j->prox;        
    }

    else

    printf("Lista vazia.");

    printf("\n\n"); 
}

void verificaPar(TLista p1, TLista p2)
{
    TLista i,j, cont=0;
    
    if((p1)&&(p2))
    {
        for (i=p1,j=p2; p1!=NULL;p2=p2->prox,p1=p1->prox)
        {
            if (i->nConteudo!=j->nConteudo)
            {
                printf("NAO SAO IGUAIS - LISTAS DIFERENTES!\n");
                    cont=0;
                        break;
            }
            else 
            {
                cont++;
            }
            
            i=i->prox;
            
            j=j->prox;          
        }
            if (cont)
            {
                printf("AS LISTAS SAO IDENTICAS\n");
            }
    }    
    
    else
        
    printf("LISTAS IDENTICAS PORQUE AMBAS SAO VAZIAS.");
}


-----------------------------------------------------------


void retiraValor(Lista* lista) {
    Lista* minhalista = lista;
    while (minhalista != NULL) {
        Lista* innerList = lista;
        int equal = 0;
        while (innerList != NULL) {
            if (innerList->valor == minhalista->valor) {
                equal++;
            }
            if (equal == 2) {
                retirarNo(lista, minhalista->valor);
                break;
            }
            innerList = innerList->proximo;
        }
        minhalista = minhalista->proximo;
    }
}
Sua abordagem estava meio vaga, o processo de remover itens duplicados em uma lista desordenada duplamente encadeada é bastante custoso. No algoritimo basicamente para cada item da lista, percorri a lista novamente a procura de mais de uma ocorrência do mesmo valor e utilizei a sua função retirarNo para tira-lo da lista.

Testei com a função main desta forma:

int main(int argc, char *argv[]) {
    Lista *lista;
    lista = criarLista();

    Lista *lista2;
    lista2 = lista;

    lista = inserirNaLista(lista, 6);
    lista = inserirNaLista(lista, 10);
    lista = inserirNaLista(lista, 7.25);
    lista = inserirNaLista(lista, 5);
    lista = inserirNaLista(lista, 10);
    lista = inserirNaLista(lista, 23);

    imprimirLista(lista);
    printf("\n");

    retiraValor(lista);

    imprimirLista(lista);

  return 0;
}



-----------------------------------


typedef struct elemento_s elemento_t;
typedef struct matriz_s matriz_t;


struct elemento_s
{
    int valor;
    elemento_t * abaixo;
    elemento_t * direita;
};


struct matriz_s
{
    elemento_t * inicio;
    int linhas;
    int colunas;
};


matriz_t * matriz_criar( int linhas, int colunas )
{
    int l = 0;
    int c = 0;
    elemento_t * esq = NULL;
    elemento_t * prim = NULL;
    elemento_t * ant = NULL;
    elemento_t * inicio = NULL;

    for( l = 0; l < linhas; l++ )
    {
        esq = NULL;

        for( c = 0; c < colunas; c++ )
        {
            elemento_t * el = (elemento_t*) calloc( 1, sizeof(elemento_t) );

            el->valor = 0;

            if( !inicio )
                inicio = el;

            if( esq )
                esq->direita = el;

            esq = el;

            if( ant )
            {
                int i = 0;
                elemento_t * aux = ant;

                for( i = 0; i < c; i++ )
                    aux = aux->direita;

                aux->abaixo = el;
            }

            if( c == 0 )
                prim = el;
        }

        ant = prim;
    }

    matriz_t * m = (matriz_t*) calloc( 1, sizeof(matriz_t) );

    m->inicio = inicio;
    m->colunas = colunas;
    m->linhas = linhas;

    return m;
}


void matriz_destruir( matriz_t * m )
{
    elemento_t * ec = m->inicio;
    elemento_t * el = NULL;
    elemento_t * aux = NULL;

    while( ec )
    {
        el = ec->direita;

        while(el)
        {
            aux = el->direita;
            free(el);
            el = aux;
        }

        aux = ec->abaixo;
        free(ec);
        ec = aux;
    }

    free(m);
}


elemento_t * matriz_obter_elemento( matriz_t * m, int col, int linha )
{
    int i = 0;
    elemento_t * e = m->inicio;

    for( i = 0; i < linha; i++ )
        e = e->abaixo;

    for( i = 0; i < col; i++ )
        e = e->direita;

    return e;
}


void matriz_setar_elemento( matriz_t * m, int col, int linha, int valor )
{
    elemento_t * e = matriz_obter_elemento( m, col, linha );
    e->valor = valor;
}


void matriz_debug( matriz_t * m )
{
    int l = 0;
    int c = 0;

    printf("matriz=%p, colunas=%d, linhas=%d, inicio=%p\n", m, m->colunas, m->linhas, m->inicio );

    for( l = 0; l < m->linhas; l++ )
    {
        for( c = 0; c < m->colunas; c++ )
        {
            elemento_t * e = matriz_obter_elemento( m, c, l );
            printf("    col=%d, linha=%d, elemento=%p, abaixo=%p, direita=%p, valor=%d\n", c, l, e, e->abaixo, e->direita, e->valor );
        }
    }

}

int main( void )
{
    int qtd_linhas = 3;
    int qtd_colunas = 5;

    /* Criando Matriz */
    matriz_t * m = matriz_criar( qtd_linhas, qtd_colunas );

    /* Preenchendo Elementos da Linha 0 */
    matriz_setar_elemento( m, 0, 0, 10 );
    matriz_setar_elemento( m, 1, 0, 20 );
    matriz_setar_elemento( m, 2, 0, 30 );
    matriz_setar_elemento( m, 3, 0, 40 );
    matriz_setar_elemento( m, 4, 0, 50 );

    /* Preenchendo Elementos da Linha 1 */
    matriz_setar_elemento( m, 0, 1, 60 );
    matriz_setar_elemento( m, 1, 1, 70 );
    matriz_setar_elemento( m, 2, 1, 80 );
    matriz_setar_elemento( m, 3, 1, 90 );
    matriz_setar_elemento( m, 4, 1, 100 );

    /* Preenchendo Elementos da Linha 2 */
    matriz_setar_elemento( m, 0, 2, 110 );
    matriz_setar_elemento( m, 1, 2, 120 );
    matriz_setar_elemento( m, 2, 2, 130 );
    matriz_setar_elemento( m, 3, 2, 140 );
    matriz_setar_elemento( m, 4, 2, 150 );

    /* Debug da Matriz */
    matriz_debug(m);

    /* Destruindo Matriz */
    matriz_destruir(m);

    return 0;
}


-------------------------------------------------


#include "biblioteca.h"

ElemM *lm;
ElemA *la;
ElemB *lb;
//---------------------------MAIN--------------------------------->

int main()
{
  lb = cria_lista_banda();
  la =  cria_lista_album();
  lm = cria_lista_musica();


  system("PAUSE");  
  return 0;
} 
//----------------------------------------------------------------->

ElemB *cria_lista_banda(){
        ElemB *lb;
        lb =  malloc(sizeof(ElemB));
        lb->prox_banda = NULL;
        return lb;


}

ElemA *cria_lista_album(){
        ElemA *la;
        la =  malloc(sizeof(ElemA));
        la->prox_album= NULL;
        return la;


}

ElemM *cria_lista_musica(){
        ElemM *lm;
        lm =  malloc(sizeof(ElemM));
        lm->prox_musica= NULL;
        return lm;


}

int incluir_musica(ElemM *lm, ElemA *la, ElemB *lb, int id_m, int tempo, char *nome_m, int id_a, int id_b){
        int valor1, valor2, valor3, i;

        valor1 = busca_banda(id_b, lb);
        valor2 = busca_album(id_b, id_a, lb, la);
        valor3 = busca_musica(id_b, id_a, id_m, lb, la, lm);
        if(valor3 == -1) return -1;

        ElemB *q;
        q = lb->prox_banda;
        for(i = 0; i <= valor1; i++){
              q = q->prox_banda;
        }
        ElemA *p;
        p = q->albuns_da_banda->prox_album;
        for(i = 0; i <= valor2; i++){
             p = p->prox_album;         
        }

        ElemM *novo, *novocpy;
        p->musicas_do_album->novo = malloc( sizeof(ElemM));
        novocpy = p->musica_do_album->novo;
        if(novo == NULL) return 0;
        novocpy->id_musica = id_m;
        novocpy->tempo_da_musica = tempo;
        strcpy(novocpy->nome_musica, nome_m);
        novocpy->prox_musica = lc->prox_musica;
        lm->prox_musica = novocpy;
        return 1;
}

int busca_banda(int id, ElemB *lb){
        int cont = 0;
        ElemB *p;
        p = lb->prox_banda;
        while(p != NULL && p->id_banda != id){
                p = p->prox_banda;
                cont++;
        }
        if(p == NULL) return -1;
        return cont;
}

int buscar_album(int id_b, int id_a, ElemB *lb, ElemR *la){
        int valor_busca = busca_banda(id_b, lb); 
        int i;
        int cont = 0;

        if(valor_busca == -1) return -1;
        ElemB *q;
        q = lb->prox_banda;
        for(i = 0; i <= valor_busca; i++){
              q = q->prox_banda;
        }
        ElemA *p;
        p = q->albuns_da_banda->prox_album;
        while(p != NULL && p->id_album != id_a){
             p = p->prox_album;
             cont++;         
        }      

        if(p != NULL) return -1;
        return cont;   

}


int buscar_musica(int id_b, int id_a, int id_m, ElemB *lb, ElemA *la, ElemM *lm){
        int valor_busca1 = busca_banda(id_b, lb);
        int valor_busca2 = busca_album(id_b, id_a, lb, la); 
        int i;
        int cont = 0;

        if(valor_busca1 == -1) return -1;
        if(valor_busca2 == -1) return -1;
        ElemB *q;
        q = lb->prox_banda;
        for(i = 0; i <= valor_busca1; i++){
              q = q->prox_banda;
        }
        ElemA *p;
        p = q->albuns_da_banda->prox_album;
        for(i = 0; i <= valor_busca2; i++){
             p = p->prox_album;         
        }
        ElemM *k;
        k = p->musica_do_album->prox_musica;
        while(k != NULL && k->id_musica != id_m){
             k = k->prox_musica;
             cont++;         
        }       

        if(k != NULL) return -1;
        return cont;   

        #include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct musica{
       int id_musica;
       int tempo_musica;
       char nome_musica[30];
       struct musica *prox_musica;
       };      

typedef struct musica ElemM;

struct album{
       int id_album;
       char nome_album[30];
       struct musica *musica_do_album;
       struct album *prox_album;
       };

typedef struct album ElemA;

struct banda{
       int id_banda;
       char nome_banda[30];
       struct album *albuns_da_banda;
       struct banda *prox_banda;
       };       

typedef struct banda ElemB;


ElemB *cria_lista_banda();
ElemR *cria_lista_album();
ElemC *cria_lista_musica();
int incluir_musica(ElemM *lm, ElemA *la, ElemB *lb, int id_m, int tempo, char *nome_m, int id_a, int id_b)
int busca_banda(int id, ElemB *lb);
int buscar_album(int id_b, int id_a, ElemB *lb, ElemR *la);
int buscar_musica(int id_b, int id_a, int id_m, ElemB *lb, ElemA *la, Elem

--------------------------------------------------



void reverseR(NODE **head) {

    /* Tratar lista vazia */
    if (*head == NULL) return;

    /* Atribuir um ponteiro para o nó atual
       e outro ponteiro para o restante da lista */
    NODE *curr;
    NODE *rest;
    curr = *head;
    rest = curr->next;

    /* Retornar ao chegar no final da lista */
    if (rest == NULL) return;

    /* Chamar a recursão até atingir o final da lista */
    reverseR(&rest);

    /* Inverter os nós e acertar a cabeça da lista */
    curr->next->next = curr;
    curr->next = NULL;
    *head = rest;
}


------------------------------------


int remove_item(ldisp **l, int id){
    if(!(*l)) // encerra se não houver item na lista
        return 0;

    ldisp *aux = (*l);
    if((*l)->idAviao == id){ // verifica se posição == 0
        (*l) = (*l)->prox; // coloca a lista no próximo item
        free(aux); // limpa a memória

        return 1; // finaliza com verdadeiro
    }

    ldisp *prev;
    while(aux){ // verifica se aux não chegou ao fim e percorre a posição
        prev = aux; // prev guarda valor da remoção
        aux = aux->prox;
        if(aux && aux->idAviao == id){ // verifica o id do avião
            prev->prox = aux->prox;
            free(aux);
            return 1;
        }
    }
    return 0;
}

-------------------------------*************



//---------------------CONCATENAÇÃO DAS LISTAS--------------------------------------



-----------------------REMOVE------------------------------------



-----------------------------------GERA DADOS ARQUIVO------------------------


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
///////// ESTRUTURAS //////////////

typedef struct cliente{
	int id;
	char nome[80];
	char valor[80];
}TCliente;

typedef struct noCliente {
	TCliente cliente;
	struct noCliente* prox;		
}NoCLiente;

typedef struct noClienteRef {
	NoCLiente * clienteRef;
	struct noClienteRef* prox;
	struct noClienteRef* ant;		
}NoCLienteRef;

typedef struct list {
	int size;
	void * head;
	void * fim;
}TList;

////// DECLARAÇÃO DE FUNÇÕES //////
TList* createList();
void add(TList* list, TCliente cliente);
void lerarquivo(TList* listaCliente);
void quebraStr(TList* listaCliente,char string[100]);
void del(TList* listaCliente);
void ordenarLista(TList* listaOriginal, TList* listaDestino, int opOrdena);
void bubbleSort(TList* listaCliente) ;
void geraDadosCsv(TList* listaCliente, char TCSV[30]);

///////// FUNÇÕES ////////////////

TList* createList(){
	TList* listCliente = (TList*)malloc(sizeof(TList));
	
	listCliente->size = 0;
	listCliente->head = NULL;		 
	
	return listCliente;
}

void geraDadosCsv(TList* listaCliente, char TCSV[30]){


		FILE * arquivoCsv;
			
            arquivoCsv = fopen(TCSV, "r");
            if(arquivoCsv==NULL)
            {
	 			arquivoCsv = fopen(TCSV, "w");
                printf("Arquivo CSV criado! \n\n");
                
            } 

	    arquivoCsv=fopen(TCSV,"w"); 

     	NoCLienteRef* aux = listaCliente->head;
     	bool i=true;
	while(aux!= NULL){
		if(i==true){
		 fprintf(arquivoCsv,"id;nome;saldo\n");
		 i=false;
		}
		 fprintf(arquivoCsv,"%d;%s;%s", aux->clienteRef->cliente.id, aux->clienteRef->cliente.nome, aux->clienteRef->cliente.valor);
		 aux = aux->prox;
	}
     	             
     printf("\n Arquivo CSV gerado com sucesso!\n");     
	 
	 fclose(arquivoCsv);  
	
}

bool listaVazia(TList* listaCliente){
	return (listaCliente->size ==0);
}

void add(TList* listaCliente, TCliente cliente){
	NoCLiente* noCliente = (NoCLiente*) malloc(sizeof(NoCLiente));
	
	
	noCliente->cliente = cliente;
	noCliente->prox = listaCliente->head;
	
	listaCliente->head = noCliente;
	
	if(listaCliente->size ==0){
		listaCliente->fim = noCliente;
	}
	listaCliente->size++; 	
}

void addRef(TList* listaCliente, NoCLiente * clienteRef){
	NoCLienteRef* noClienteRef = (NoCLienteRef*) malloc(sizeof(NoCLienteRef));
	
	NoCLienteRef * aux = listaCliente->head;
	noClienteRef->clienteRef = clienteRef;
	noClienteRef->prox = listaCliente->head;
	noClienteRef->ant = NULL;
	listaCliente->head = noClienteRef;
	
		if(listaCliente->size !=0){
		aux->ant = noClienteRef;
		listaCliente->head = noClienteRef;
	}
	
	if(listaCliente->size ==0){
		listaCliente->fim = noClienteRef;
	}
	listaCliente->size++; 
				
}

void del(TList* listaCliente){
	
NoCLiente *no = listaCliente->head, *aux;
    while (no != NULL)
    {
        aux = no;
        no = no->prox;
        free (aux);
    }
    listaCliente->size  = 0;
    listaCliente->head = NULL;
}

void lerArquivo(TList* listaCliente){
	
  FILE *arqTxt;
  char Linha[100];
  char *result;
  int i;
 
  // Abre um arquivo TEXTO para LEITURA
  arqTxt = fopen("DadosBanco.txt", "rt");
 	
	if (arqTxt == NULL)
	{
	    printf("Problemas na LEITURA do arquivo\n");
	    return;
	}else{
		printf("\n LEITURA DO ARQUIVO OK! \n");
	}
	
  i = 1;
  while (!feof(arqTxt))
  {

     result =  fgets(Linha, 100, arqTxt);
      if (result) {
     	quebraStr(listaCliente, Linha);	
	  }
      
      i++;
  }
  
  fclose(arqTxt);
  printf(" \n DADOS INSERIDOS COM SUCESSO!\n");
   
}

void imprimeLista(TList* listaCliente ){
		
	if(listaVazia(listaCliente)){
		printf("LISTA VAZIA! \n");
		return;
	}
	
	NoCLiente* aux = listaCliente->head;
	printf("\n===============================================");
	while(aux!= NULL){
		printf("\n %d - %s - %s", aux->cliente.id, aux->cliente.nome, aux->cliente.valor);
		aux = aux->prox;
	}
	printf("\n===============================================");
	printf("\n");
}

void imprimeListaRef(TList* listaCliente ){
		
	if(listaVazia(listaCliente)){
		printf("LISTA VAZIA! \n");
		return;
	}
	
	NoCLienteRef* aux = listaCliente->head;
	printf("\n===============================================");
	while(aux!= NULL){
	
		printf("\n %d - %s - %s", aux->clienteRef->cliente.id, aux->clienteRef->cliente.nome, aux->clienteRef->cliente.valor);
		
		aux = aux->prox;
	}
	printf("\n===============================================");
	printf("\n");
}

void quebraStr(TList* listaCliente,char string[100]){
	
	
    char v[3][80];
	
   TCliente cliente;
   const char s[2] = "|";
   char* strQuebrada;
   
 	int i = 0;
   strQuebrada = strtok(string, s);
	 
   while( strQuebrada != NULL ) {

    	if(i==0){
    		cliente.id = atoi(strQuebrada);
		}else
		if(i==1){
			 sprintf(cliente.nome, "%s", strQuebrada);
		}else
		if(i==2){
			sprintf(cliente.valor, "%s", strQuebrada);	
		}
	    i++;
	   
      strQuebrada = strtok(NULL, s);

   }
   
     add(listaCliente, cliente);
}

void setListRef(TList* listaOriginal, TList* listaDestino){
	
	 if(listaVazia(listaOriginal)){
		printf("LISTA ORIGINAL VAZIA! \n");
		return;
	}
	
	if(!listaVazia(listaDestino)){
	
		while(listaDestino->size!=0){
			
		del(listaDestino);
		
	}
	listaDestino->size = 0;
	listaDestino->head = NULL;
	}
	
	NoCLiente* aux = (NoCLiente*) malloc(sizeof(NoCLiente));
 	aux  = listaOriginal->head;
 
	while(aux != NULL){
					
				addRef(listaDestino, aux);
					aux = aux->prox;
	}
	free(aux);

	
}

void bubbleSort(TList* listaCliente) {  

	if(listaCliente->size ==0){
		printf("\n LISTA VAZIA! \n");
		return;
	}
	
	NoCLienteRef* aux_cli = listaCliente->head;
		
		while (aux_cli != NULL ){
				NoCLienteRef* aux_cli2 = aux_cli->prox;
		    while (aux_cli2 != NULL ){
		    
		      if ( strcmp(  aux_cli->clienteRef->cliente.nome,  aux_cli2->clienteRef->cliente.nome)>0){ 
		      
		       			   NoCLiente * temp = aux_cli->clienteRef;   			   
		       			   aux_cli->clienteRef = aux_cli2->clienteRef;
		       			   aux_cli2->clienteRef = temp;
		        }
				aux_cli2 = aux_cli2->prox;
		    }
			aux_cli = aux_cli->prox;  
		}

}


NoCLienteRef *partition (NoCLienteRef *inicio, NoCLienteRef * fim){
	NoCLienteRef * esq = inicio; 
	NoCLienteRef * dir = fim;
	NoCLienteRef * pivot = inicio;
	

	while(inicio!=fim){
		while(atof( esq->clienteRef->cliente.valor) < atof( pivot->clienteRef->cliente.valor)){
			inicio  = inicio->prox;
			esq = esq->prox;			
		}
		while(atof(dir->clienteRef->cliente.valor) > atof(pivot->clienteRef->cliente.valor)){
			fim  = fim->ant;
			dir = dir->ant;			
		}
		
		if(atof(esq->clienteRef->cliente.valor) > atof(  dir->clienteRef->cliente.valor)){
			NoCLiente * temp = esq->clienteRef;
			esq->clienteRef = dir->clienteRef;
			dir->clienteRef = temp;
		}
		
	}
	
	inicio->clienteRef  =dir->clienteRef;
	dir->clienteRef = pivot->clienteRef;
	
	return dir;
	
}
void quickSort(NoCLienteRef* l, NoCLienteRef *h) 
{ 
	
     if(h!=NULL && h->prox!=l ){ 
    
        NoCLienteRef *p = partition(l, h); 
        quickSort(l, p->ant); 
        quickSort(p->prox, h); 
    } 
} 


int main(int argc, char *argv[]) {
		
	TList * listaOriginal = createList();
	TList * listaNome = createList();
	TList * listaSaldo = createList();
	
	clock_t TOrdenacao[2];
   
	
	TCliente cliente;

	int escolha=-1;

while (escolha!=0){

printf("\n\n =============================== ");

	printf("\n 1 - SET DADOS LISTA ORIGINAL ");
	printf("\n 2 - IMPRIMIR LISTA ORIGINAL");
	printf("\n 3 - SET DADOS LISTA NOME ");
	printf("\n 4 - IMPRIMIR LISTA NOME");
	printf("\n 5 - SET DADOS LISTA SALDO ");
	printf("\n 6 - IMPRIMIR LISTA SALDO");
	printf("\n 7 - ORDENA BUBBLESORT NOME");
	printf("\n 8 - ORDENA QUICKSORT SALDO");
	printf("\n 9 - GERA CSV NOME - SALDO");
	printf("\n 0 - SAIR");
	printf("\n\n Escolha uma opcao: ");
	scanf("%d",&escolha);

	switch (escolha) {

	case 1:
	{	system("cls");
	printf("\n SETA VALORES PARA LISTA - NOME \n");
		lerArquivo(listaOriginal);		
	break;
	}
	case 2:
	{	system("cls");
		printf("\n IMPRIME LISTA ORIGINAL \n");
		imprimeLista(listaOriginal);		
	break;
	}
	case 3:
	{	system("cls");
		printf("\n SETA VALORES PARA LISTA - NOME \n");
		setListRef(listaOriginal,listaNome);		
	break;
	}
	case 4:
	{	system("cls");
		printf("\n IMPRIME LISTA NOME \n");
		imprimeListaRef(listaNome);		
	break;
	}
	case 5:
	{	system("cls");
		printf("\n SETA VALORES PARA LISTA - SALDO \n");
		setListRef(listaOriginal,listaSaldo);		
	break;
	}
	case 6:
	{	system("cls");	
		printf("\n IMPRIME LISTA SALDO \n");
		imprimeListaRef(listaSaldo);		
	break;
	}
	case 7:
	{	system("cls");
		printf(" \n ORDENA - BUBBLESORT - NOME ");
		TOrdenacao[0] = clock();
		bubbleSort(listaNome);
		TOrdenacao[1] = clock();
  		printf("\n TEMPO ORDENACAO : BUBBLESORT %f", (TOrdenacao[1] - TOrdenacao[0]) * 1000.0 / CLOCKS_PER_SEC);
		printf("\n================================");
	
	break;
	}
	case 8:
	{	system("cls");
	
		if(listaSaldo->size ==0){
		printf("\n LISTA VAZIA! \n");
	}else{
		printf(" \n ORDENA - QUICKSORT - SALDO ");
		TOrdenacao[0] = clock();
		quickSort(listaSaldo->head, listaSaldo->fim);
		TOrdenacao[1] = clock();
 		printf("\n TEMPO ORDENACAO : QUICKSORT %f", (TOrdenacao[1] - TOrdenacao[0]) * 1000.0 / CLOCKS_PER_SEC);
		printf("\n================================");	
	
	}
	break;
	}
	case 9:
	{	system("cls");
		 	printf("\n GERA DADOS CSV LISTA NOME \n");
			geraDadosCsv(listaNome,"NomeCSV.csv");
	
			printf("\n GERA DADOS CSV LISTA SALDO \n");
	
			geraDadosCsv(listaSaldo,"SaldoCSV.csv");
	break;
	}
	
	}
}


	return 0;
------------------------------------------------------

--------------------------JOGO DA FORCA------------------------------









