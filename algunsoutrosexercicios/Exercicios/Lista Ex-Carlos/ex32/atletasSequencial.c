#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOME 50

/*Escrever um procedimento de
inclus�o rand�mica de 1 a n registros em um arquivo com dados de atletas. O seguinte tipo, utilizado
no procedimento, � definido externamente ao mesmo:
Tipo atlet = registro
cod: inteiro
nome: string
idade: inteiro
altura: real
fim registro
Os dados de cada atleta est�o na posi��o correspondente ao seu c�digo. Para cada inclus�o, deve
inicialmente ser fornecido um c�digo v�lido. Feito isso, s�o solicitados os dados para a inclus�o: nome,
idade e altura. Uma mensagem de erro � exibida em caso de tentativa de inclus�o para inexistente. O
usu�rio, ap�s cada tentativa de inclus�o, decide se quer seguir com as inclus�es ou parar. O procedimento
recebe o nome l�gico do arquivo e qual o maior c�digo v�lido. � utilizado um procedimento auxiliar
para acessar o arquivo e verificar se a posi��o onde ser� feita a inclus�o est� livre.*/

typedef struct {
    int cod;
    char nome[MAX_NOME];
    int idade;
    float altura;
} atlet;

int posicao_livre(FILE *arquivo, int codigo) {
    atlet a;
    int posicao = (codigo - 1) * sizeof(atlet); // posi��o do registro no arquivo

    fseek(arquivo, posicao, SEEK_SET); // posicionar o ponteiro do arquivo na posi��o do registro
    fread(&a, sizeof(atlet), 1, arquivo); // ler o registro

    return (a.cod == 0); // a posi��o est� livre se o c�digo do registro � 0
}

void inclusao_aleatoria_arquivo(char *nome_arquivo, int maior_codigo) {
    atlet a;
    int codigo;
    char continuar = 's';
    FILE *arquivo;

    srand(time(NULL)); // inicializar o gerador de n�meros aleat�rios

    arquivo = fopen(nome_arquivo, "r+b"); // abrir o arquivo para leitura e escrita bin�ria

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (continuar == 's' || continuar == 'S') {
        codigo = rand() % maior_codigo + 1; // obter um c�digo v�lido aleat�rio entre 1 e maior_codigo

        if (posicao_livre(arquivo, codigo)) {
            a.cod = codigo;

            printf("Digite o nome do atleta: ");
            fgets(a.nome, MAX_NOME, stdin);
            a.nome[strcspn(a.nome, "\n")] = '\0'; // remover o caractere '\n' do final da string

            printf("Digite a idade do atleta: ");
            scanf("%d", &a.idade);

            printf("Digite a altura do atleta: ");
            scanf("%f", &a.altura);

            fseek(arquivo, (codigo - 1) * sizeof(atlet), SEEK_SET); // posicionar o ponteiro do arquivo na posi��o do registro
            fwrite(&a, sizeof(atlet), 1, arquivo); // escrever o registro no arquivo

            printf("Registro inclu�do com sucesso.\n");
        } else {
            printf("N�o foi poss�vel incluir o registro para o c�digo %d.\n", codigo);
        }

        printf("Deseja continuar (S/N)? ");
        scanf(" %c", &continuar);
        getchar(); // remover o caractere '\n' do buffer de entrada
    }

    fclose(arquivo); // fechar o arquivo
}

int main() {
    char nome_arquivo[MAX_NOME];
    int maior_codigo;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arquivo, MAX_NOME, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0'; // remover o caractere '\n' do final da string

    printf("Digite o maior c�digo v�lido: ");
    scanf("%d", &maior_codigo);

    inclusao_aleatoria_arquivo(nome_arquivo, maior_codigo);

    return 0;
}
