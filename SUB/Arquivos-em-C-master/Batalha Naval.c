/* Jogo - Batalha Naval */ 
 
#include<stdio.h>
#include<stdlib.h>
//Constante para definir o tamanho limite da senha
#define tamSenha 8

//Protótipo da função BatalhaNaval
void BatalhaNaval();

int main(){
	typedef struct {
		char nome[30];
		char senha[8];
	} Jogador;
	
	//Declaração do ponteiro Senha e abertura do arquivo
	FILE *Senha;
	Senha=fopen("senha.txt","w+b");
	
	//Variável de controle da estrutura de repetição for
	int i;
	//Variável para acessar a struct
	Jogador jogadores;
	
	printf("### BATALHA NAVAL ###\n\n\n");
	printf("Insira o seu nome: ");
	gets(jogadores.nome);
	printf("Digite uma senha (maximo de 8 caracteres): ");
	//Estrutura de repetição para...
	for (i=0;i<tamSenha;i++){
		jogadores.senha[i]=getch();//Coletar a senha do usuário caractere por caractere
		if (jogadores.senha[i]==13){//Estrutura condicional para caso o caractere inserido seja ENTER(13)...
			break;//a estrutura de repetição é interrompida
		}
		printf("*");//Exibe asteriscos (*) ao invés dos caracteres
	}
	//Chama a função BatalhaNaval
	BatalhaNaval();
return 0;
}

//Execução da função
void BatalhaNaval(){
	//Declara a matriz do inimigo com valores atribuídos
    char inimigo[5][10] =  {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                           {0, 1, 1, 1, 1, 0, 0, 1, 0, 1},
                           {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {1, 0, 1, 1, 1, 0, 0, 0, 0, 0}};
    
    FILE *Resultado;
    Resultado=fopen("resultado.txt","a+");
	
	//Declara o tabuleiro do Jogador
	char tabuleiro[5][10];
    
	//Contadores para matriz, onde i=linha e j=coluna | Numero de jogadas
	int i, j, jogadas;
    
	//Limpa a tela
    system("cls");
    
	//Estrutura de repetição para imprimir o tabuleiro inicial do jogador
    for(i=0; i<5; i++){
             for(j=0; j<10; j++){
                      tabuleiro[i][j] = '.';
                      printf("%c", tabuleiro[i][j]);
             }
             printf("\n");
    }
    
    //Coleta as coordenadas do usuário
    printf("Informe as coordenadas do tiro (linha | coluna): ");
    scanf("%d %d", &i, &j);
    
    //Estrutura de repetição para...
    while(i>-1 && j>-1){
    			system("cls");
    			//Checar se o usuário acertou o adversário ou não, imprimindo o acerto/erro
               if(inimigo[i][j] == 1){
                                tabuleiro[i][j] = 'X';
               }
               else{
                    tabuleiro[i][j] = 'O';
                    printf("\nJogadas: %d\n",++jogadas);
               }
               //mostra o tabuleiro novamente mas atualizado
               for(i=0; i<5; i++){ 
                        for(j=0; j<10; j++){
                                 printf("%c", tabuleiro[i][j]);
                        }
                        printf("\n");
               }
               //Coleta novas coordenadas do jogador
               printf("Informe as coordenadas do tiro (linha coluna): ");
               scanf("%d %d", &i, &j);
    }
    
    system("pause");
}
