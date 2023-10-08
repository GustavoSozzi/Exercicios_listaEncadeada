#include <stdio.h>

typedef struct{
    int dia, mes, ano;
}DataNasc;

typedef struct{
    DataNasc datanasc;
    int idade;
    char sexo;
    char nome[100];
}Pessoa;

void imprimir_pessoa(Pessoa p){ //nao retorna nada

printf("\nNOME: %s: ", p.nome);
printf("Idade: %d: ", p.idade);
printf("sexo %c:", p.sexo);
printf("\nDatanascimento: %d/%d/%d", p.datanasc.dia, p.datanasc.mes, p.datanasc.ano);

}

//funcao que le os dados de uma pessoa e retorna para quem chamou

Pessoa lerpessoa(){
    Pessoa p;

fgets(p.nome, 100, stdin);
scanf("%d", &p.idade);
scanf("%c");
scanf("%c", &p.sexo);
scanf("%d", &p.datanasc.dia);
scanf("%d", &p.datanasc.mes);
scanf("%d", &p.datanasc.ano);

return p;


}

int main(){

Pessoa pessoa;

pessoa = lerpessoa(); //recebendo retorno da funcao lerpessoa

imprimir_pessoa(pessoa); //imprimindo as informacoes

return 0;
}

/*int main(){

    Pessoa pessoa;

fgets(pessoa.nome, 100, stdin);
scanf("%d", &pessoa.idade);
scanf("%c");
scanf("%c", &pessoa.sexo);
scanf("%d", &pessoa.datanasc.dia);
scanf("%d", &pessoa.datanasc.mes);
scanf("%d", &pessoa.datanasc.ano);

imprimir_pessoa(pessoa);

return 0;
}*/
