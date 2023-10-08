//--------------EXERCICIO 1------------

#include <stdio.h>

void binario(int num)
{
    if (num>0)
    {
        binario(num/2);
        printf("%i",num%2);
    }
}

int main()
{
    binario(6);
    return 0;
}

//-------------EXERCICIO 2---------------------------

#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int quant;
    float preco;
}Prod;

void busca(Prod lista[],int qProd,Prod listaS[],int *qProdS,float preco)
{
    int i;
    (*qProdS)=0;
    for (i=0;i<qProd;qProd++)
    {
        if (lista[i].preco<=preco)
        {printf("Achou\n");
            listaS[*qProdS].preco = lista[i].preco;
            listaS[*qProdS].quant = lista[i].quant;
            strcpy(listaS[*qProdS].nome,lista[i].nome);
            (*qProdS)++;
        }
    }
}

void print(Prod lista[],int tam)
{
    int i;
    printf("\n_______________________\n");
    printf("\n::::Produtos::::\n\n");
    for (i=0;i<tam;i++)
    {
        printf("Nome: %s - Quant: %i - Preco: R$ %.2f\n",lista[i].nome,lista[i].quant,lista[i].preco);
    }
    printf("\n_______________________\n");
}

int main()
{
    FILE *file = fopen("ListaDeComprasDoJorginho.txt","r");
    Prod lista[1000],listaS[1000];
    int qProd = 0,qProdS;
    float preco;

    if (file==NULL)
    {
        return 0;
    }

    while (!feof(file))
    {
        fscanf(file,"%[^;];%i;%f\n",lista[qProd].nome,&lista[qProd].quant,&lista[qProd].preco);
        qProd++;
    }
    print(lista,qProd);

    printf("Digite o valor a comparar: ");
    scanf("%f",&preco);
    busca(lista,qProd,listaS,&qProdS,preco);
    print(listaS,qProdS);
    return 0;
}

//---------------------EXERCICIO 3--------------------------

#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int quant;
    float preco;
}Prod;

void busca(Prod lista[],int qProd,Prod listaS[],int *qProdS,float preco)
{
    int i;
    (*qProdS)=0;
    for (i=0;i<qProd;qProd++)
    {
        if (lista[i].preco<=preco)
        {printf("Achou\n");
            listaS[*qProdS].preco = lista[i].preco;
            listaS[*qProdS].quant = lista[i].quant;
            strcpy(listaS[*qProdS].nome,lista[i].nome);
            (*qProdS)++;
        }
    }
}

void print(Prod lista[],int tam)
{
    int i;
    printf("\n_______________________\n");
    printf("\n::::Produtos::::\n\n");
    for (i=0;i<tam;i++)
    {
        printf("Nome: %s - Quant: %i - Preco: R$ %.2f\n",lista[i].nome,lista[i].quant,lista[i].preco);
    }
    printf("\n_______________________\n");
}

int main()
{
    FILE *file = fopen("ListaDeComprasDoJorginho.txt","r");
    Prod lista[1000],listaS[1000];
    int qProd = 0,qProdS;
    float preco;

    if (file==NULL)
    {
        return 0;
    }

    while (!feof(file))
    {
        fscanf(file,"%[^;];%i;%f\n",lista[qProd].nome,&lista[qProd].quant,&lista[qProd].preco);
        qProd++;
    }
    print(lista,qProd);

    printf("Digite o valor a comparar: ");
    scanf("%f",&preco);
    busca(lista,qProd,listaS,&qProdS,preco);
    print(listaS,qProdS);
    return 0;
}

//---------------EXERCICIO 4-----------------

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




