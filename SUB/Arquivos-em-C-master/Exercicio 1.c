/* ATIVIDADE 03 - 22/05/2015 - LISTA COM INSERÇÃO, REMOVAÇÃO E IMPRESSAO
QUESTÃO 03 - Este programa cria uma lista dinâmica de registros com os seguintes
dados fornecidos pelo usuário: nome, distância e tempo. 
O campo velocidade é preenchido pela divisão entre a distância e o tempo. 
Essa lista cresce sempre no final, ou seja, os
novos registros são inseridos no final dela, 
sendo possível excluir elementos da lista.*/
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
	 t_info info;//variável info do tipo t_info
	 struct t_no *prox;//ponteiro prox do tipo t_no
 } t_no;
 
 //Protótipos das funções
 void inicializa();//inicializa a lista
 int vazia();//verifica se a lista está vazia
 void lerDados();//le os dados do usuario
 void insere_primeiro(t_info info);//insere o elemento no inicio da lista
 t_no *obterUltimo();//obtém o ultimo elemento da lista
 void insere_final(t_info info);//insere o elemento no final da lista
 void mostrar_tudo();//mostra toda a lista
 void mostrar_primeiro();//mostra apenas o primeiro elemento da lista
 void mostrar_ultimo();//mostra apenas o ultimo elemento da lista
 void remover(char nome[]);//remove o elemento escolhido da lista
 int menu();//menu do programa

 t_no *L;//ponteiro L do tipo t_no
 t_info novoDado;//variável para manipular a estrutura t_info
//função para iniciar a lista
 void inicializa() 
 {
 	L == NULL;
 }
//função para verificar se a lista estã vazia...
 int vazia() 
 {
 	return ( L == NULL ? 1 : 0); // se L = NULL então retorna V (1) senão F (0)
 }
 //Função para ler os dados  do usuário
 void lerDados() 
 {
	 printf("\n\n=== Lendo os dados ===\n");
	 printf("Nome......: ");
	 fflush(stdin);
	 gets(novoDado.nome);//lê o nome para variável nome da struct novoDado
	 printf("Distancia.: ");
	 scanf("%f", &novoDado.distancia);//lê a distancia para variável distancia da struct novoDado
	 printf("Tempo.....: ");
	 scanf("%f", &novoDado.tempo);//le o tempo para a variavel distancia da struct novoDado
	
	 // Calcula a velocidade.
	 novoDado.velocidade = novoDado.distancia / novoDado.tempo;
 }
 //função para inserir no primeiro elemento
 void insere_primeiro(t_info info) 
 {
	 t_no *p = malloc(sizeof (t_no));//ponteiro p aponta para o espaço alocado na memória do tipo t_no
	 p->info = info;//info do nó recebe as informações passadas por parametro
	 p->prox = NULL;//ponteiro proximo do nó aponta para NULO
	 L = p;//lista aponta para o elemento inserido
 }
 // funcao do tipo t_no que retorna o último elemento da lista. 
 // Se estiver vazia, retorna NULL.
 t_no *obterUltimo() 
 {
	 
	 t_no *aux = L;//ponteiro aux do tipo t_no aponta para onde L está apontando
	
	 if (vazia()) //se a lista estiver vazia...
	 { 
	  	return NULL;//retorna NULO
	  
	 }
	 while (aux->prox != NULL) //se o ponteiro prox do elemento for diferente de NULO...
	 {
	 	aux = aux->prox;//aux recebe o endereço do próximo elemento
	 }
	 return aux;//retorna o endereço de auxiliar
 }
 
 //insere um elemento no final da lista
 void insere_final(t_info info) {
	 t_no *p = malloc(sizeof (t_no));//aloca um espaço no heap do tipo t_no que é apontado por p
	 t_no *ult = obterUltimo();//ponteiro ult recebe o endereço retornado pela função obterUltimo
	 p->info = info;//variavel info do nó recebe as informações inseridas pelu usuário
	 p->prox = NULL;//ponteiro próximo do nó aponta para NULO
	 ult->prox = p; // Coloca o nó p na última posição da lista.
 }
//função para mostrar todos os elementos
 void mostrar_tudo() 
 {
 	t_no *aux = L;//ponteiro aux do tipo t_no aponta para L

	 if (aux == NULL)//se o ponteiro aux apontar para nulo
	 {
		 printf("\n Lista vazia! \n");
		 return;//sai da função
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
//Função para mostrar o primeiro elemento	
void mostrar_primeiro() 
{
	if (L == NULL) //se L aponta para nulo... 
	{
	 	printf("\n Lista vazia! \n");
	 	return;//sai da função
	}	 
	 
	 printf("\n++++++ PRIMEIRO ELEMENTO ++++++\n");
	 printf("\nNome.: %s\n", L->info.nome);//imprime o nome
	 printf("Dist.: %3.2f\n", L->info.distancia);//imprime a distancia
	 printf("Tempo: %3.2f\n", L->info.tempo);//imprime o tempo
	 printf("Velo.: %3.2f\n", L->info.velocidade);//imprime a velocidade
 }
//Função para mostrar o ultimo elemento...	 
 void mostrar_ultimo() 
 {
	 t_no *aux = obterUltimo();//ponteiro aux recebe o endereço retornado pela função obterUltimo();
	
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
	 t_no *aux = L;//ponteiro auxiliar do tipo t_no aponta para onde L está apontando 
	 t_no *antecessor;//ponteiro antecessor do tipo t_no
	 int achou = 0;//variável achou iniciada com 0
	
	 // Verifica se o nó está no início da lista e remove.
	 // strcmp retorna 0 se strings são iguais.
	 if (!strcmp(aux->info.nome, nome)) 
	 {
		 L = L->prox; // Marca o início da lista como o próximo elemento.
		 free(aux); // Apaga o nó da memória.
		 printf("\n NO removido com sucesso \n");
		 return;//retorna da função, sai dela (porque o tipo é void)
 	 }

 // Se o nó não está no início da lista, busca o nó e seu antecessor.
	 while (aux->prox != NULL) 
	 {
		 antecessor = aux;//ponteiro antecessor aponta para onde aux está apontando
		 aux = aux->prox;//ponteiro aux aponta para onde prox está apontando
		 if (!strcmp(aux->info.nome, nome)) { // achou o nó
		 achou = 1;
		 break;
	}
 }

 // Ao término do loop acima, se “achou == 1”, então encontrou o elemento
 // e podemos remover. Caso “achou == 0”, o elemento não foi encontrado.
	 if (achou) 
	 {
		 antecessor->prox = aux->prox;//ponteiro prox do elemento anterior aponta para onde o prox de auxiliar está apontando
		 free(aux);//libera o espaço alocado pelo ponteiro aux
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
	 int opcao;//variável para receber a Opção
	 char aux[50];//variável auxiliar para guardar o nome
	
	 inicializa();//chamar a função para inicializar a lista
	 do//faça...
	 {
			 opcao = menu();//recebe o valor retornado pela função menu();
			 switch (opcao) 
			 {
				 case 0:  break;//quebra o switch
				 case 1: // inserir
				 	lerDados();//chama a função para ler os dados
						 if (vazia()) 
						 { // se lista vazia, insere primeiro
						 	insere_primeiro(novoDado);
						 }
						 else { // senão insere no final
						 	insere_final(novoDado);
						 }
						 break;
				 case 2: // remover nó
					 if (!vazia()) 
					 {
						 mostrar_tudo();//chama a função para mostrar todos os elemtnos da lista
						 printf("\nDigite o nome que deseja remover: ");
						 fflush(stdin);//limpa o buffer de inserção
						 gets(aux);//le o nome e salva na variãvel aux
						 remover(aux);//chama a função remover passando a variável aux como parâmetro
				     }
				 else
				 	printf("\n Lista vazia! \n");
				 	break;
				 case 3:
				 	mostrar_tudo();//chama a função para mostrar todos os elementos
				 	break;
				 case 4:
				 	mostrar_primeiro();//chama a função  para mostrar o primeiro elemento
				 	break;
				 case 5:
				 	mostrar_ultimo();//chama a função para mostrar o ultimo elemento
				 	break;
				 default:
				 	printf("_____________Opcao invalida_____________\n\n");
				 }
	} while (opcao != 0);//enquanto opcao for diferente de 0

 return 0;
 }
