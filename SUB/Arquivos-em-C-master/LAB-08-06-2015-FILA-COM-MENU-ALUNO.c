 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 // Estrutura para os elementos com o campo info e o campo prox.
 typedef struct {
 char info[30];
 struct t_no *prox;
 } t_no;

 // Estrutura para a fila.
 typedef struct {
 	t_no *no;
 	t_no *comeco,*fim;
 } t_fila;

 t_fila *F;//criar um ponteiro que vai apontar para a etrutura fila
 char novoDado[30];
 
 void criar_fila() {
 	F = malloc(sizeof(t_fila));
 	F->comeco = NULL;
 	F->fim = NULL;
 }
 
 
 int vazia() 
 {
 	return (F->comeco == NULL? 1 : 0);//Verifica se a lista está vazia, se sim, retorna 1, se não, retorna 0
 }

 void inserir(char novoDado[]) 
 {
 	t_no *aux = malloc(sizeof(t_no));//aloca o no
 	
 	strcpy(aux->info, novoDado);//insere novo dado	
	
	if(vazia())// Se lista vazia, então insere o primeiro elemento
		F->comeco = aux;
	else // Campo prox do último elemento da lista aponta para o novo elemento aux.
		F->fim->prox = aux;
	
 	F->fim = aux;// Atualiza o final da lista para o novo elemento.
 }
 
 
 void lerDados() 
 {
	 printf("\n\n=== Lendo os dados ===\n");
	 printf("Digite um nome: ");
	 fflush(stdin);
	 gets(novoDado);
 }
 
 int menu() 
 {
 int opcao;
	 printf("\n\n Opcoes possiveis \n");
	 printf("0 - Sair\n");
	 printf("1 - Inserir na fila\n");
	 printf("2 - Remover da fila\n");
	 printf("3 - Mostrar fila\n");
	 printf("\nO que deseja fazer? ");
	 scanf("%d", &opcao);
 return opcao;
 }

 int main() 
 {
 int opcao;

 	 criar_fila();
 	 
	 do 
	 {
	 opcao = menu();
		 switch (opcao) 
		 {
			 case 0: 
			 	break;
			 case 1: // inserir
				 lerDados();
				 inserir(novoDado);
				 break;
			 case 2: // remover
			 	//remover();
			 	break;
			 case 3: // exibir lista
			 	//mostrar();
			 	break;
		 	default:
		 	printf("_____________Opcao invalida_____________\n\n");
		 }
	 } while (opcao != 0);
 return 0;
 }
