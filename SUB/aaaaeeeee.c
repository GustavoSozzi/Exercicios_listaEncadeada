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

