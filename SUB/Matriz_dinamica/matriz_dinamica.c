/*
	Implementa��o de matriz esparsa usando lista duplamente ligada
	www.GeeksBR.com
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // m�ximo do vetor de c�lulas (ver na fun��o main)


/*
	Estrutura c�lula contendo os seguintes campos:
		- valor
		- linha e coluna (posi��o da c�lula)
		- ponteiro para o pr�ximo elemento
		- ponteiro para o elemento anterior
*/
typedef struct celula
{
	int valor;
	int lin, col;
	struct celula *prox;
	struct celula *ant;
} t_celula;


// vari�veis globais
t_celula *primeiro; // primeiro elemento da lista
t_celula *ultimo; // �ltimo elemento da lista


// prot�tipos de fun��es
t_celula* criar_celula(int lin, int col, int valor);
void inserir(t_celula *novo);
void deletar(int lin, int col);
int vazia();
t_celula* existe_celula(int lin, int col);
void imprimir_elementos();
void imprimir_matriz();


/* Fun��o que cria uma nova celula passando a linha e coluna */
t_celula* criar_celula(int lin, int col, int valor)
{
	t_celula * novo;

	// aloca espa�o em mem�ria
	novo = (t_celula*)malloc(sizeof(t_celula));

	// testa se houve falha na aloca��o
	if(!novo)
	{
		printf("Erro ao alocar memoria!!\n");
		exit(1);
	}

	// atribui��o de vari�veis
	novo->valor = valor;
	novo->lin = lin;
	novo->col = col;

	return novo;
}


/*
	Fun��o que insere um novo elemento (c�lula) na matriz esparsa
	A lista � ordenada de acordo com o nome da c�lula
*/
void inserir(t_celula *novo)
{
	/*
		obt�m uma c�lula passando a linha e coluna do novo elemento
		para verificar se a posi��o j� est� ocupada
	*/
	t_celula* cel = existe_celula(novo->lin, novo->col);

	if(!cel) // verifica se n�o existe
	{
		if(!ultimo)
		{
			/*
				Se o "ultimo" � NULL, ent�o a lista est� vazia, o "novo"
				ser� o primeiro elemento a ser inserido
			*/

			// o pr�ximo e o anterior apontam para NULL
			novo->prox = NULL;
			novo->ant = NULL;

			// faz o "ultimo" e "primeiro" apontarem para "novo"
			ultimo = novo;
			primeiro = novo;
		}
		else
		{
			// "p" serve para percorrer a lista
			// "ant" aponta para o anterior de "p"
			t_celula *p, *ant;


			p = primeiro; // come�a do topo da lista
			ant = p->ant; // "ant" � o anterior ao "p", ou seja, NULL

			// poderia fazer tamb�m: ant = NULL;

			// percorre a lista
			while(p) // enquanto "p" diferente de NULL
			{
				/*
					Se a c�lula corrente "p" precede a
					c�lula "novo", ent�o continua percorrendo
				*/
				if((p->lin < novo->lin) || ((p->lin == novo->lin) && (p->lin + p->col) < (novo->lin + novo->col)))
				{
					ant = p; // guarda o anterior
					p = p->prox; // aponta para o pr�ximo
				}
				else
				{
					/*
						Se cair aqui � porque encontramos
						onde inserir a nova c�lula
					*/

					/*
						Se p->ant � diferente de NULL, ent�o trata-se
						de um elemento intermedi�rio
					*/
					if(p->ant)
					{
						/*
							p->ant � a c�lula que cont�m um nome imediatamente
							anterior � nova c�lula que ser� invetserida.
							Ent�o dizemos que o pr�ximo de p->ant ir� apontar
							para essa nova c�lula
						*/
						p->ant->prox = novo;

						/*
							Se p->ant � a c�lula imediatamente anterior �
							c�lula "novo", ent�o "p" � a c�lula imediatamente
							posterior � c�lula "novo", por isso dizendos que o
							pr�ximo de "novo" aponta para "p'.
						*/
						novo->prox = p;

						// novo->ant tem que apontar para o p->ant
						novo->ant = p->ant;

						// faz p->ant apontar para o novo
						p->ant = novo; // corre��o de: novo->avetnt = i;

						return; // sai da fun��o
					}

					/*
						Se chegar aqui � porque p->ant � NULL, ent�o
						iremos inserir o novo elemento no in�cio, ou seja,
						o "novo" ser� o novo primeiro da lista
					*/

					novo->prox = p; // o pr�ximo do novo aponta para "p"
					novo->ant = NULL; // o anterior aponta para NULL (primeiro da lista)
					p->ant = novo; // faz o anterior de "p" apontar para o novo
					primeiro = novo; // "primeiro" aponta para "novo"

					return; // sai da fun��o
				}
			}

			/*
				Se chegou aqui, ent�o insere no final, agora preciso
				da vari�vel "ant".
			*/

			// faz o pr�x. do antigo �ltimo apontar para "novo"
			ant->prox = novo;

			// como o "novo" agora � o �ltimo, ent�o o pr�ximo dele
			// aponta para NULL
			novo->prox = NULL;

			// o anterior ao "novo" aponta para o "ant"
			novo->ant = ant;

			// atualiza o �ltimo elemento da lista
			ultimo = novo;
		}
	}
	else
	{
		// se j� existe ent�o sobrescreve o valor
		cel->valor = novo->valor;
	}
}


// Fun��o que deleta um elemento pela posi��o (linha e coluna)
void deletar(int lin, int col)
{
	// verifica se existe a c�lula (elemento)
	if(existe_celula(lin, col))
	{
		// remove do come�o
		if(primeiro->lin == lin && primeiro->col == col)
		{
			// pego o apontador para o pr�ximo
			t_celula *prox = primeiro->prox;

			free(primeiro); // libera mem�ria

			// verifico se o pr�ximo existe
			if(prox)
				prox->ant = NULL; // atualizo o anterior

			// faz o "primeiro" ser o "prox"
			primeiro = prox;

			return; // sai da fun��o
		}

		/*
			Se chegou aqui � porque N�O ir� remover do in�cio e
			existe mais de 1 elemento
		*/
		t_celula *p = primeiro->prox;

		// percorre a lista
		while(p)
		{
			if(p->lin == lin && p->col == col)
			{
				if(p->prox) // testa se N�O � o �ltimo elemento
				{
					/*
						Fa�o o pr�ximo do anterior de "p" apontar
						para o pr�ximo de "p"
					*/
					p->ant->prox = p->prox;

					/*
						Fa�o o anterior do proximo de "p" apontar
						para o anterior de "p"
					*/
					p->prox->ant = p->ant;
				}
				else
				{
					// se chegou aqui, � porque � o �ltimo elemento

					// faz o proximo do anterior de "p" apontar para NULL
					p->ant->prox = NULL;

					// faz o anterior de "p" ser o "ultimo"
					ultimo = p->ant;
				}

				free(p); // libera o "p"
				return; // sai da fun��o
			}
			p = p->prox;
		}
	}
}


// Fun��o que verifica se a lista est� vazia
int vazia()
{
	if(!ultimo) // se o �ltimo for NULL, ent�o a lista est� vazia
		return 1;
	return 0;
}


// Fun��o que verifica se um elemento existe pela posi��o (linha e coluna)
t_celula* existe_celula(int lin, int col)
{
	t_celula* p = primeiro;

	while(p) // percorre a lista
	{
		// verifica a linha e a coluna
		if(lin == p->lin && col == p->col)
			return p; // retorna a c�lula
		p = p->prox;
	}
	return NULL;
}


// Fun��o que imprime os lementos da lista
void imprimir_elementos()
{
	t_celula* p = primeiro;

	while(p) // percorre a lista
	{
		printf("(%d,%d)\n", p->lin, p->col);
		p = p->prox;
	}
}


// Fun��o para imprimir a matriz convencional
// "X" indica o elemento repetido da matriz esparsa (pode ser um 0 por exemplo)
void imprimir_matriz()
{
	if(!vazia()) // verifica se a lista N�O est� vazia
	{
		/*
			Obtendo a maior linha, basta saber a do �ltimo
			porque est� ordenado pela linha
		*/
		int total_linhas = ultimo->lin;

		// obtendo o total de colunas
		int total_colunas = -1;
		t_celula* p = primeiro;
		while(p) // percorre a lista para obter o total de colunas
		{
			if(p->col > total_colunas)
				total_colunas = p->col;
			p = p->prox;
		}

		for(int i = 0; i < total_linhas; i++)
		{
			for(int j = 0; j < total_colunas; j++)
			{
				// busca por um elemento passando a linha e coluna
				t_celula* cel = existe_celula(i + 1, j + 1);

				if(cel) // testa se encontrou o elemento
					printf("%d\t", cel->valor);
				else // se n�o existe o elemento, ent�o imprime 'X'
					printf("X\t");
			}
			printf("\n");
		}
	}
	else
		printf("\nLista vazia!!\n");
}


int main(int argc, char * argv[])
{
	t_celula *vet[MAX]; // vetor de c�lulas

	// passa a linha e coluna da c�lula
	vet[0] = criar_celula(2, 1, 10);
	vet[1] = criar_celula(1, 2, 20);
	vet[2] = criar_celula(10, 3, 30);
	vet[3] = criar_celula(1, 1, 40);
	vet[4] = criar_celula(3, 2, 50);
	vet[5] = criar_celula(2, 8, 60);
	vet[6] = criar_celula(3, 1, 70);
	vet[7] = criar_celula(4, 2, 80);
	vet[8] = criar_celula(3, 3, 90);
	vet[9] = criar_celula(1, 6, 100);

	if(vazia()) // verifica se a lista est� vazia
		printf("\nLista vazia!!\n");
	else
		printf("\nLista NAO vazia!!\n");

	// insere os elementos (c�lulas)
	for(int i = 0; i < MAX; i++)
		inserir(vet[i]);

	if(vazia()) // verifica se a lista est� vazia
		printf("\nLista vazia!!\n");
	else
		printf("\nLista NAO vazia!!\n");

	printf("\nImprimindo os elementos da lista:\n");
	imprimir_elementos(); // imprime a matriz

	printf("\nImprimindo a matriz esparsa (X eh o elemento que se repete):\n");
	imprimir_matriz(); // imprime a matriz

	deletar(10, 3); // deletando a c�lula da posi��o (10,3)

	printf("\nImprimindo a matriz esparsa (X eh o elemento que se repete):\n");
	imprimir_matriz(); // imprime a matriz

	return 0;
}
