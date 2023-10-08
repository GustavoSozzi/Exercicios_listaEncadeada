#include <stdio.h>

#define TAM_MAX 100

int size(char txt[]);
void concatena2(char txt1[],char txt2[],char txt3[]);

int main()
{
    char txt[TAM_MAX];
    char txt3[TAM_MAX*2];

    printf("Digite a frase: ");
    scanf("%[^\n]s",txt);

    concatena2(txt," da terra",txt3);
    printf("%s\n",txt3);

    return 0;
}

int size(char txt[])
{
    int i;
    for (i=0;i<TAM_MAX && txt[i]!='\0';i++)
    {}

    return i;
}

void concatena2(char txt1[],char txt2[],char txt3[])
{
    int tam1 = size(txt1);
    int tam2 = size(txt2);
    int i=0,j=0;

    for (i=0,j=0;i<tam1 || j<tam2;)
    {
        if (i<tam1)
        {
            txt3[i]=txt1[i];
            i++;
        }
        if (j<tam2)
        {
            txt3[j+tam1]=txt2[j];
            j++;
        }
    }
    txt3[tam1+tam2]='\0';
}
