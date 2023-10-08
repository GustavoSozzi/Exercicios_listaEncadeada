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
/*Aula.14-02-2023.c
Exibindo Aula.14-02-2023.c�
Aula 05 - Arquivos
Carlos Elias Arminio Zampieri
�
24 de jan. Editado �s 14 de fev.

Roteiro05-Arquivos-Opera��es_sobre_arquivos_sequenciais_e_aleat�rios.pdf
PDF

Exerc�ciosArquivos.pdf
PDF

Aula.14-02-2023.c
C

pokemon.txt
Texto
Coment�rios da turma*/
