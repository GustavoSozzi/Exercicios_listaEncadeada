//Rai Roney
#include <stdio.h>
#include <assert.h>
 typedef struct {
	 char nome[30];
	 char sexo ;
} Cliente;
 
struct nodo
{
   int valor;
   struct nodo *prox;
 };

nodo *k;
Cliente Pcliente; 

void iniciar()
{
Cliente ==NULL;
}
int vazia() 
 {
 	return ( k == NULL ? 1 : 0); // se k = NULL então retorna verdadeiro ou falso 
 }
 
 nodo *obterUltimo() 
 {
	 
	 nodo *aux = L;
	
	 if (vazia()) 
	 { 
	  	return NULL;
	  
	 }
	 while (aux->prox != NULL) 
	 {
	 	aux = aux->prox;
	 }
	 return aux;
 }
  void insere_primeiro(t_info info) 
 {
	 nodo *p = malloc(sizeof (t_no));
	 p->valor = info;
	 p->prox = NULL;
	 k = p;
 }
void insere_fim (struct nodo **inicio, struct nodo **fim, int v, int *status)
{
     nodo *p = malloc(sizeof (nodo));
	 nodo *ult = ultimo();
	 p->valo = valor ;
	 p->prox = NULL;
	 ult->prox = p;

 } 
void exclui5 (struct nodo *inicio,struct nodo **fim,int *v,int *status)
{ 
	 
	 nodo *aux = k;
	 nodo *antecessor;
	 int achou = 0;
	
	 if (!strcmp(aux->info.nome, nome)) 
	 {
		 k = k->prox; 
		 free(aux); // libera memoria .
		 printf("\n NO removido com sucesso \n");
		 return;
 	 }

 
	 while (aux->prox != NULL) 
	 {
		 antecessor = aux;
		 aux = aux->prox;
		 if (!strcmp(aux->Cliente.nome, nome)) { 
		 break;
	}
 }

 	 if (achou) 
	 {
		 antecessor->prox = aux->prox;
		 free(aux);
		 printf("\n  removido com sucesso \n");
	 }
	 else
	 	printf("\n  nao encontrado \n");
	 }

	
}
void ler() 
 {
	 printf("\n\n=== Lendo os dados ===\n");
	 printf("digite um nome: ");
	 fflush(stdin);
	 gets(pcliente.nome);
	 printf("digite seu sexo M ou F: ");
	 fflush(stdin);
	 gets(pcliente.sexo);
}
 int main() 
{
	 int opcao;
	 iniciar();
	 do 
	 {
			 opcao = menu();
			 switch (opcao) 
			 {
				 case 0:  break;
				 case 1: // inserir
				 	ler();
						 if (vazia()) 
						 { 
						 	insere_primeiro(novoDado);
						 }
						 else { // senão insere no final
						 	insere_final(novoDado);
						 }
						 break;
				 case 2: 
					 if (!vazia()) 
					 {
						 mostrar_tudo();
						 printf("\nDigite o nome que deseja remover: ");
						 fflush(stdin);
						 gets(aux);
						 remover(aux);
				     }
				 else
				 	printf("\n Lista vazia! \n");
				 	break;
				
				 default:
				 	printf("_Opcao invalida \n");
				 }
	} while (opcao != 0);

 return 0;
 }
