/* ATIVIDADE 03 - 22/05/2015 - LISTA COM INSER��O, REMOVA��O E IMPRESSAO
QUEST�O 03 - Este programa cria uma lista din�mica de registros com os seguintes
dados fornecidos pelo usu�rio: nome, dist�ncia e tempo. 
O campo velocidade � preenchido pela divis�o entre a dist�ncia e o tempo. 
Essa lista cresce sempre no final, ou seja, os
novos registros s�o inseridos no final dela, 
sendo poss�vel excluir elementos da lista.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Structs
 typedef struct {
	 char nome[50];
	 float distancia;
	 float tempo;
	 float velocidade;
 } t_info;
 
 typedef struct {
	 t_info info;//vari�vel info do tipo t_info
	 struct t_no *prox;//ponteiro prox do tipo t_no
 } t_no;
 
 //Prot�tipos das fun��es
 void inicializa();//inicializa a lista
 int vazia();//verifica se a lista est� vazia
 void lerDados();//le os dados do usuario
 void insere_primeiro(t_info info);//insere o elemento no inicio da lista
 t_no *obterUltimo();//obt�m o ultimo elemento da lista
 void insere_final(t_info info);//insere o elemento no final da lista
 void mostrar_tudo();//mostra toda a lista
 void mostrar_primeiro();//mostra apenas o primeiro elemento da lista
 void mostrar_ultimo();//mostra apenas o ultimo elemento da lista
 void remover(char nome[]);//remove o elemento escolhido da lista
 int menu();//menu do programa

 t_no *L;//ponteiro L do tipo t_no
 t_info novoDado;//vari�vel para manipular a estrutura t_info
//fun��o para iniciar a lista
 void inicializa() 
 {
 	L == NULL;
 }
//fun��o para verificar se a lista est� vazia...
 int vazia() 
 {
 	return ( L == NULL ? 1 : 0); // se L = NULL ent�o retorna V (1) sen�o F (0)
 }
 //Fun��o para ler os dados  do usu�rio
 void lerDados() 
 {
	 printf("\n\n=== Lendo os dados ===\n");
	 printf("Nome......: ");
	 fflush(stdin);
	 gets(novoDado.nome);//l� o nome para vari�vel nome da struct novoDado
	 printf("Distancia.: ");
	 scanf("%f", &novoDado.distancia);//l� a distancia para vari�vel distancia da struct novoDado
	 printf("Tempo.....: ");
	 scanf("%f", &novoDado.tempo);//le o tempo para a variavel distancia da struct novoDado
	
	 // Calcula a velocidade.
	 novoDado.velocidade = novoDado.distancia / novoDado.tempo;
 }
 //fun��o para inserir no primeiro elemento
 void insere_primeiro(t_info info) 
 {
	 t_no *p = malloc(sizeof (t_no));//ponteiro p aponta para o espa�o alocado na mem�ria do tipo t_no
	 p->info = info;//info do n� recebe as informa��es passadas por parametro
	 p->prox = NULL;//ponteiro proximo do n� aponta para NULO
	 L = p;//lista aponta para o elemento inserido
 }
 // funcao do tipo t_no que retorna o �ltimo elemento da lista. 
 // Se estiver vazia, retorna NULL.
 t_no *obterUltimo() 
 {
	 
	 t_no *aux = L;//ponteiro aux do tipo t_no aponta para onde L est� apontando
	
	 if (vazia()) //se a lista estiver vazia...
	 { 
	  	return NULL;//retorna NULO
	  
	 }
	 while (aux->prox != NULL) //se o ponteiro prox do elemento for diferente de NULO...
	 {
	 	aux = aux->prox;//aux recebe o endere�o do pr�ximo elemento
	 }
	 return aux;//retorna o endere�o de auxiliar
 }
 
 //insere um elemento no final da lista
 void insere_final(t_info info) {
	 t_no *p = malloc(sizeof (t_no));//aloca um espa�o no heap do tipo t_no que � apontado por p
	 t_no *ult = obterUltimo();//ponteiro ult recebe o endere�o retornado pela fun��o obterUltimo
	 p->info = info;//variavel info do n� recebe as informa��es inseridas pelu usu�rio
	 p->prox = NULL;//ponteiro pr�ximo do n� aponta para NULO
	 ult->prox = p; // Coloca o n� p na �ltima posi��o da lista.
 }
//fun��o para mostrar todos os elementos
 void mostrar_tudo() 
 {
 	t_no *aux = L;//ponteiro aux do tipo t_no aponta para L

	 if (aux == NULL)//se o ponteiro aux apontar para nulo
	 {
		 printf("\n Lista vazia! \n");
		 return;//sai da fun��o
	 }
	 printf("\n++++++ TODOS OS ELEMENTOS ++++++\n");
	 
	 while (aux != NULL) 
	 {
		 printf("\nNome.: %s\n", aux->info.nome);//imprime o nome
		 printf("Dist.: %3.2f\n", aux->info.distancia);//imprime a distancia
		 printf("Tempo: %3.2f\n", aux->info.tempo);//imprime o tempo
		 printf("Velo.: %3.2f\n", aux->info.velocidade);//imprime a velocidade
		 aux = aux->prox;
	 }
}
//Fun��o para mostrar o primeiro elemento	
void mostrar_primeiro() 
{
	if (L == NULL) //se L aponta para nulo... 
	{
	 	printf("\n Lista vazia! \n");
	 	return;//sai da fun��o
	}	 
	 
	 printf("\n++++++ PRIMEIRO ELEMENTO ++++++\n");
	 printf("\nNome.: %s\n", L->info.nome);//imprime o nome
	 printf("Dist.: %3.2f\n", L->info.distancia);//imprime a distancia
	 printf("Tempo: %3.2f\n", L->info.tempo);//imprime o tempo
	 printf("Velo.: %3.2f\n", L->info.velocidade);//imprime a velocidade
 }
//Fun��o para mostrar o ultimo elemento...	 
 void mostrar_ultimo() 
 {
	 t_no *aux = obterUltimo();//ponteiro aux recebe o endere�o retornado pela fun��o obterUltimo();
	
	 if (aux == NULL)//se aux aponta para nulo... 
	 {
	 	printf("\n Lista vazia! \n");
	 	return;
	 }
	 printf("\n++++++ ULTIMO ELEMENTO ++++++\n");
	 printf("\nNome.: %s\n", aux->info.nome);//imprime o nome
	 printf("Dist.: %3.2f\n", aux->info.distancia);//imprime a distancia
	 printf("Tempo: %3.2f\n", aux->info.tempo);//imprime o tempo
	 printf("Velo.: %3.2f\n", aux->info.velocidade);//imprime a velocidade
 }
 void remover(char nome[]) 
 {
	 // Remove um elemento buscando pelo nome.
	 t_no *aux = L;//ponteiro auxiliar do tipo t_no aponta para onde L est� apontando 
	 t_no *antecessor;//ponteiro antecessor do tipo t_no
	 int achou = 0;//vari�vel achou iniciada com 0
	
	 // Verifica se o n� est� no in�cio da lista e remove.
	 // strcmp retorna 0 se strings s�o iguais.
	 if (!strcmp(aux->info.nome, nome)) 
	 {
		 L = L->prox; // Marca o in�cio da lista como o pr�ximo elemento.
		 free(aux); // Apaga o n� da mem�ria.
		 printf("\n NO removido com sucesso \n");
		 return;//retorna da fun��o, sai dela (porque o tipo � void)
 	 }

 // Se o n� n�o est� no in�cio da lista, busca o n� e seu antecessor.
	 while (aux->prox != NULL) 
	 {
		 antecessor = aux;//ponteiro antecessor aponta para onde aux est� apontando
		 aux = aux->prox;//ponteiro aux aponta para onde prox est� apontando
		 if (!strcmp(aux->info.nome, nome)) { // achou o n�
		 achou = 1;
		 break;
	}
 }

 // Ao t�rmino do loop acima, se �achou == 1�, ent�o encontrou o elemento
 // e podemos remover. Caso �achou == 0�, o elemento n�o foi encontrado.
	 if (achou) 
	 {
		 antecessor->prox = aux->prox;//ponteiro prox do elemento anterior aponta para onde o prox de auxiliar est� apontando
		 free(aux);//libera o espa�o alocado pelo ponteiro aux
		 printf("\n NO removido com sucesso \n");
	 }
	 else
	 	printf("\n Elemento nao encontrado \n");
	 }

int menu() 
{
		 int opcao;		
		 printf("\n\n Opcoes possiveis \n");
		 printf("0 - Sair\n");
		 printf("1 - Inserir\n");
		 printf("2 - Excluir\n");
		 printf("3 - Mostrar todos\n");
		 printf("4 - Mostrar primeiro\n");
		 printf("5 - Mostrar ultimo\n");
		 printf("\nO que deseja fazer? ");
		 scanf("%d", &opcao);//le o numero do usuario e guarda na variavel opcao
		 return opcao;//retorna a variavel opcao
}

/******* programa principal *****/

 int main() 
{
	 int opcao;//vari�vel para receber a Op��o
	 char aux[50];//vari�vel auxiliar para guardar o nome
	
	 inicializa();//chamar a fun��o para inicializar a lista
	 do//fa�a...
	 {
			 opcao = menu();//recebe o valor retornado pela fun��o menu();
			 switch (opcao) 
			 {
				 case 0:  break;//quebra o switch
				 case 1: // inserir
				 	lerDados();//chama a fun��o para ler os dados
						 if (vazia()) 
						 { // se lista vazia, insere primeiro
						 	insere_primeiro(novoDado);
						 }
						 else { // sen�o insere no final
						 	insere_final(novoDado);
						 }
						 break;
				 case 2: // remover n�
					 if (!vazia()) 
					 {
						 mostrar_tudo();//chama a fun��o para mostrar todos os elemtnos da lista
						 printf("\nDigite o nome que deseja remover: ");
						 fflush(stdin);//limpa o buffer de inser��o
						 gets(aux);//le o nome e salva na vari�vel aux
						 remover(aux);//chama a fun��o remover passando a vari�vel aux como par�metro
				     }
				 else
				 	printf("\n Lista vazia! \n");
				 	break;
				 case 3:
				 	mostrar_tudo();//chama a fun��o para mostrar todos os elementos
				 	break;
				 case 4:
				 	mostrar_primeiro();//chama a fun��o  para mostrar o primeiro elemento
				 	break;
				 case 5:
				 	mostrar_ultimo();//chama a fun��o para mostrar o ultimo elemento
				 	break;
				 default:
				 	printf("_____________Opcao invalida_____________\n\n");
				 }
	} while (opcao != 0);//enquanto opcao for diferente de 0

 return 0;
 }
