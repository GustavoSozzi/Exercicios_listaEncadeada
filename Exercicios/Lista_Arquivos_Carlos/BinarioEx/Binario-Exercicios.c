typedef struct {
    char nome[50];
    char telefone[15];
    int dia_aniversario;
    int mes_aniversario;
} Contato;

void inserirContato(Contato contatos[], int *numContatos);
void removerContato(Contato contatos[], int *numContatos);
void pesquisarContato(Contato contatos[], int numContatos);
void listarContatos(Contato contatos[], int numContatos);
void listarContatosPorLetra(Contato contatos[], int numContatos, char letra);
void imprimirAniversariantesDoMes(Contato contatos[], int numContatos, int mes);

int main() {
    Contato contatos[MAX_CONTATOS];
    int numContatos = 0;
    char opcao;
    char letra;
    int mes;

    // Tenta abrir o arquivo para leitura dos contatos salvos
    FILE *arquivo = fopen("contatos.bin", "rb");
    if (arquivo != NULL) {
        fread(&numContatos, sizeof(int), 1, arquivo);
        fread(contatos, sizeof(Contato), numContatos, arquivo);
        fclose(arquivo);
        printf("Contatos carregados do arquivo.\n");
    }

    do {
        printf("\nEscolha uma opção:\n");
        printf("a) Inserir contato\n");
        printf("b) Remover contato\n");
        printf("c) Pesquisar contato pelo nome\n");
        printf("d) Listar todos os contatos\n");
        printf("e) Listar contatos por letra\n");
        printf("f) Imprimir aniversariantes do mês\n");
        printf("s) Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'a':
                inserirContato(contatos, &numContatos);
                break;
            case 'b':
                removerContato(contatos, &numContatos);
                break;
            case 'c':
                pesquisarContato(contatos, numContatos);
                break;
            case 'd':
                listarContatos(contatos, numContatos);
                break;
            case 'e':
                printf("Letra: ");
                scanf(" %c", &letra);
                listarContatosPorLetra(contatos, numContatos, letra);
                break;
            case 'f':
                printf("Mês: ");
                scanf("%d", &mes);
                imprimirAniversariantesDoMes(contatos, numContatos, mes);
                break;
            case 's':
                printf("Salvando contatos no arquivo...\n");
                arquivo = fopen("contatos.bin", "wb");
                fwrite(&numContatos, sizeof(int), 1, arquivo);
                fwrite(contatos, sizeof(Contato), numContatos, arquivo);
                fclose(arquivo);
                printf("Contatos salvos no arquivo.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 's');

    return 0;
}


void inserir_contato(Contato *contatos, int *quantidade) {
    printf("Insira o nome: ");
    scanf("%s", contatos[*quantidade].nome);
    printf("Insira o telefone: ");
    scanf("%s", contatos[*quantidade].telefone);
    printf("Insira o dia do aniversario: ");
    scanf("%d", &contatos[*quantidade].dia_aniversario);
    printf("Insira o mes do aniversario: ");
    scanf("%d", &contatos[*quantidade].mes_aniversario);
    (*quantidade)++;
}

void remover_contato(Contato *contatos, int *quantidade) {
    char nome[50];
    printf("Insira o nome do contato a ser removido: ");
    scanf("%s", nome);
    int i;
    for (i = 0; i < *quantidade; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            (*quantidade)--;
            for (int j = i; j < *quantidade; j++) {
                contatos[j] = contatos[j+1];
            }
            printf("Contato removido com sucesso!\n");
            return;
        }
    }
    printf("Contato nao encontrado!\n");
}

void pesquisar_contato(Contato *contatos, int quantidade) {
    char nome[50];
    printf("Insira o nome do contato a ser pesquisado: ");
    scanf("%s", nome);
    int i;
    for (i = 0; i < quantidade; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Aniversario: %d/%d\n", contatos[i].dia_aniversario, contatos[i].mes_aniversario);
            return;
        }
    }
    printf("Contato nao encontrado!\n");
}

void salvarContatos(Contato contatos[], int tamanho) {
    FILE *arquivo = fopen("contatos.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de contatos.\n");
        return;
    }

    fwrite(&tamanho, sizeof(int), 1, arquivo);
    fwrite(contatos, sizeof(Contato), tamanho, arquivo);

    fclose(arquivo);
}

Contato* carregarContatos(int *tamanho) {
    FILE *arquivo = fopen("contatos.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de contatos.\n");
        return NULL;
    }

    fread(tamanho, sizeof(int), 1, arquivo);
    Contato *contatos = malloc(*tamanho * sizeof(Contato));
    fread(contatos, sizeof(Contato), *tamanho, arquivo);

    fclose(arquivo);

    return contatos;
}

void listarContatosPorLetra(Contato contatos[], int numContatos) {
    char letra;
    int i;

    if (numContatos == 0) {
        printf("Agenda vazia. Impossível listar contatos.\n");
        return;
    }

    printf("Listar contatos por letra:\n");

    printf("Digite a letra inicial: ");
    scanf(" %c", &letra);

    for (i = 0; i < numContatos; i++) {
        if (contatos[i].nome[0] == letra) {
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Aniversário: %d/%d\n", contatos[i].dia_aniversario, contatos[i].mes_aniversario);
        }
    }
}

void imprimirAniversariantesDoMes(Contato contatos[], int numContatos) {
    time_t t = time(NULL);
    struct tm *data_atual = localtime(&t);
    int mes_atual = data_atual->tm_mon + 1;
    int i, aniversariantes = 0;

    printf("Aniversariantes do mês:\n");

    for (i = 0; i < numContatos; i++) {
        if (contatos[i].mes_aniversario == mes_atual) {
            printf("%s (%d/%d)\n", contatos[i].nome, contatos[i].dia_aniversario, contatos[i].mes_aniversario);
            aniversariantes++;
        }
    }

    if (aniversariantes == 0) {
        printf("Não há aniversariantes neste mês.\n");
    }
}

