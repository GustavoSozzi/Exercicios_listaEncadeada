#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Structs
 typedef struct {
	 char NomeCliente[50];
	 int AgenciaCliente;
	 int ContaCliente;
	 float SalarioCliente;
 } t_info;
 
 typedef struct {
	 t_info info;//variável info do tipo t_info
	 struct t_no *prox;//ponteiro prox do tipo t_no
 } t_no;
 
 //Protótipos das funções
 void inicializa();//inicializa a lista
 int vazia();//verifica se a lista está vazia
 void lerDados();//le os dados do cliente
 void insere_primeiro(t_info info);//insere o elemento no inicio da lista
 t_no *obterUltimo();//obtém o ultimo elemento da lista
 void insere_final(t_info info);//insere o elemento no final da lista
 void mostrar_tudo();//mostra toda a lista
 void mostrar_primeiro();//mostra apenas o primeiro elemento da lista
 void mostrar_ultimo();//mostra apenas o ultimo elemento da lista
 void remover(char NomeCliente[]);//remove o elemento escolhido da lista
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
 	 system("cls");//limpa a tela
	 printf("-------------------CADASTRO DE CLIENTE---------------------");
	 printf("\nNome....: ");
	 fflush(stdin);
	 gets(novoDado.NomeCliente);//lê o nome para variável NomeCliente da struct novoDado
	 printf("Agencia.: ");
	 scanf("%i", &novoDado.AgenciaCliente);//lê a agencia para variável Agencia da struct novoDado
	 printf("Conta...: ");
	 scanf("%i", &novoDado.ContaCliente);//le o tempo para a variavel distancia da struct novoDado
	 printf("Salario.: ");
	 scanf("%f",&novoDado.SalarioCliente);
	 printf("\n-----------------------------------------------------------\n");
	 printf("                Cliente cadastrado com sucesso!");
	 getch();
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
	     getch();
		 return;//sai da função
	 }
	 system("cls");//limpa a tela
	 printf("-------------------CLIENTES CADASTRADOS--------------------");
	 
	 while (aux != NULL) 
	 {
		 printf("\nNome....: %s\n", aux->info.NomeCliente);//imprime o nome
		 printf("Agencia.: %i\n", aux->info.AgenciaCliente);//imprime a agencia
	     printf("Conta...: %i\n", aux->info.ContaCliente);//imprime a conta
		 printf("Salario.: %3.2f\n", aux->info.SalarioCliente);//imprime o salario
		 printf("-----------------------------------------------------------");
		 aux = aux->prox;
	 }
	 getch();
}
//Função para mostrar o primeiro elemento	
void mostrar_primeiro() 
{
	if (L == NULL) //se L aponta para nulo... 
	{
	 	printf("\n Lista vazia! \n");
		getch();
	 	return;//sai da função
	}	 
	 system("cls");//limpa a tela
	 printf("---------------------PRIMEIRO CLIENTE----------------------");
	 printf("\nNome....: %s\n", L->info.NomeCliente);//imprime o nome
	 printf("Agencia.: %i\n", L->info.AgenciaCliente);//imprime a agencia
	 printf("Conta...: %i\n", L->info.ContaCliente);//imprime a conta
	 printf("Salario.: %3.2f\n", L->info.SalarioCliente);//imprime o salario
	 printf("-----------------------------------------------------------");
	 getch();
 }
//Função para mostrar o ultimo elemento...	 
 void mostrar_ultimo() 
 {
	 t_no *aux = obterUltimo();//ponteiro aux recebe o endereço retornado pela função obterUltimo();
	
	 if (aux == NULL)//se aux aponta para nulo... 
	 {
	 	printf("\n Lista vazia! \n");
	 	getch();
	 	return;
	 }
	 system("cls");//limpa a tela
	 printf("----------------------ULTIMO CLIENTE-----------------------");
	 printf("\nNome....: %s\n", aux->info.NomeCliente);//imprime o nome
	 printf("Agencia.: %i\n", aux->info.AgenciaCliente);//imprime a agencia
	 printf("Conta...: %i\n", aux->info.ContaCliente);//imprime a conta
	 printf("Salario.: %3.2f\n", aux->info.SalarioCliente);//imprime o salario
	 printf("-----------------------------------------------------------");
	 getch();
 }
 void remover(char nome[]) 
 {
	 // Remove um elemento buscando pelo nome.
	 t_no *aux = L;//ponteiro auxiliar do tipo t_no aponta para onde L está apontando 
	 t_no *antecessor;//ponteiro antecessor do tipo t_no
	 int achou = 0;//variável achou iniciada com 0
	
	 // Verifica se o nó está no início da lista e remove.
	 // strcmp retorna 0 se strings são iguais.
	 if (!strcmp(aux->info.NomeCliente, nome)) 
	 {
		 L = L->prox; // Marca o início da lista como o próximo elemento.
		 free(aux); // Apaga o nó da memória.
		 printf("\n Cliente removido com sucesso \n");
	 	 getch();
		 return;//retorna da função, sai dela (porque o tipo é void)
 	 }

 // Se o nó não está no início da lista, busca o nó e seu antecessor.
	 while (aux->prox != NULL) 
	 {
		 antecessor = aux;//ponteiro antecessor aponta para onde aux está apontando
		 aux = aux->prox;//ponteiro aux aponta para onde prox está apontando
		 if (!strcmp(aux->info.NomeCliente, nome)) { // achou o nó
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
		 printf("\n Cliente removido com sucesso \n");
		 getch();
	 }
	 else
	 	printf("\n Cliente nao encontrado \n");
	 	getch();
	 }

int menu() 
{
		 int opcao;
		 system("cls");//limpa a tela		
		 printf("---------------------DAN's BANK S.A.-----------------------\n");
		 printf("1 - Cadastrar Cliente\n");
		 printf("2 - Excluir Cliente\n");
		 printf("3 - Mostrar todos os Clientes\n");
		 printf("4 - Mostrar primeiro Cliente\n");
		 printf("5 - Mostrar ultimo Cliente\n\n");
		 printf("0 - Sair\n");
		 printf("-----------------------------------------------------------");
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
					 	 system("cls");//limpa a tela
						 mostrar_tudo();//chama a função para mostrar todos os elemtnos da lista
						 printf("\nDigite o nome do Cliente que deseja remover: ");
						 fflush(stdin);//limpa o buffer de inserção
						 gets(aux);//le o nome e salva na variãvel aux
						 remover(aux);//chama a função remover passando a variável aux como parâmetro
				     }
				 else{
				 	printf("\n Lista vazia! \n");
					getch();
					 }
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
