//funcao que conte quantas palavras possui uma cadeia de caracteres, deve retornar a quantidade de palavras

#include <stdio.h>
#define TAM_MAX 100


int main(){

char texto[TAM_MAX];
int num_palavras;

printf("Digite um texto: ");
 scanf("%[^\n]s",texto);

int num = size(texto);

printf("Numeros de palavras e: %d", num);

return 0;
}

int size(char texto[]){

    int cont=0, i=0;
    //fgets(texto, 100, stdin); //espera uma entrada do usuario, caso queira utilizar essa funcao;

    while(texto[i]!='/n' && texto[i] != '\0'){ //enquanto nao terminou texto

        while(texto[i]==' ') i++; //pula possiveis espacoes e achou o comeco de uma palavra ou fim do texto
        //ao fazer comparacao sempre utilizar ' ' com espaço

        if(texto[i]!='\n' && texto!= '\0'){ //se achou uma palavra
            cont++;//incrementa o numero de palavras
            while(texto[i] !=' ' && texto[i] != '\n' && texto[i] != '\0') i++; //passa pela palavra
        }
    }

    return cont;

}

/*int main(){

char s[80];
int i=0, cont=0;
fgets(s, 80, stdin);

 while(s[i]!='\n' && s[i] != '\0'){ //enquanto nao terminou texto

        while(s[i]==' ') i++; //pula possiveis espacoes e achou o comeco de uma palavra ou fim do texto

        if(s[i]!='\n' && s!= '\0'){ //se achou uma palavra
            cont++;//incrementa o numero de palavras
            while(s[i] !=' ' && s[i] != '\n' && s[i] != '\0') i++; //passa pela palavra
        }
    }

    return 0;
}*/
