
/*Assinaturas das funções*/

void menu ();
/*
    Mostra as opções do menu
*/

int **ler_Matriz(int *lin, int *col);
/*
    Função que adiciona valores para as matrizes M1 e M2, Passar as variaveis que correspondem
    as linhas e colunas ds matrizes por referência foi algo necessario para que se pudesse manipulá-las
    nas outras funções;
*/

void libera_matriz(int **M, int lin);
/*
    Libera a matriz;
*/

void multiplicar_M1_M2(int **M1, int **M2, int n, int m, int p, int q);
/*
    Multiplica M1 e M2, mas antes dela ser executada, realiza-se um teste para verificar se existem valores nas matrizes. Depois, ao ser executada,
    verifica-se se a coluna(m) de M1 é igual a linha(p) de M2
*/

void multiplicar_M1_M2transposta(int **M1, int **M2, int n, int m, int p, int q);
/*
    Realiza-se um teste para verificar se existem valores nas matrizes. Depois, ao ser executada,
    verifica-se se a coluna(m) de M1 é igual a linha(q) de M2 transposta
*/

void imprime_M1transposta(int **M1, int n, int m);
/*
    Imprime a matriz M1 transposta;
*/

void imprime_linha_de_M1(int **M1, int n, int m);
/*
    Imprime uma linha de M1 informada pelo usuário;
*/

void imprime_coluna_de_M1(int **M1, int m, int n);
/*
    Imprime uma coluna de M1 informada pelo usuário;
*/
