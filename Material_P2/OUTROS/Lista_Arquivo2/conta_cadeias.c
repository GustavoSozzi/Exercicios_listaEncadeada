#include <stdio.h>

#define TAM_MAX 100

int size(char txt[]);
int size2(char txt[]);
void concatena(char txt1[],char txt2[],char txt3[]);

int main()
{
    char txt[TAM_MAX];
    char txt3[TAM_MAX*2];

    printf("Digite a frase: ");
    scanf("%[^\n]s",txt);

    printf("Quant.: %i\n",size(txt));
    printf("Quant2.: %i\n",size2(txt));

    concatena(txt," da lua",txt3);
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

int size2(char txt[])
{
    int i,cont=0;
    for (i=0;i<TAM_MAX && txt[i]!='\0';i++)
    {
        if (txt[i]!=' ')
        {
            cont++;
        }
    }
    return cont;
}

void concatena(char txt1[],char txt2[],char txt3[])
{
    int tam1 = size(txt1);
    int tam2 = size(txt2);
    int i,j;

    for (i=0;i<tam1;i++)
    {
        txt3[i] = txt1[i];
    }
    for (j=0;j<tam2;j++,i++)
    {
        txt3[i] = txt2[j];
    }
    txt3[i]='\0';
}
