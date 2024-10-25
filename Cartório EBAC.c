#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca para definir a localidade
#include <string.h> // Biblioteca respons�vel por cuidar das strings

int registro() {
    char arquivo[50];
    char cpf[50];
    char nome[50];
    char sobrenome[50];
    char cargo[50];
    int x = 0;

    do {
        printf("Digite o CPF:  ");
        scanf("%s", cpf);
        strcpy(arquivo, cpf);
        strcat(arquivo, ".txt");

        FILE *file = fopen(arquivo, "w");
        if (file == NULL) {
            printf("Erro ao criar o arquivo.\n");
            return -1; // Retorna erro
        }
        fprintf(file, "%s", cpf);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ", ");
        fclose(file);

        printf("Digite o seu nome: ");
        scanf("%s", nome);
        file = fopen(arquivo, "a");
        fprintf(file, "%s", nome);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ", ");
        fclose(file);

        printf("Digite o seu sobrenome: ");
        scanf("%s", sobrenome);
        file = fopen(arquivo, "a");
        fprintf(file, "%s", sobrenome);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ", ");
        fclose(file);

        printf("Digite o seu cargo: ");
        scanf("%s", cargo);
        file = fopen(arquivo, "a");
        fprintf(file, "%s\n", cargo);
        fclose(file);

        char conf; // Confirma��o
        while (1) {
            printf("\nDeseja inserir outro usu�rio? (S/N): ");
            getchar(); // Limpa o buffer
            scanf("%c", &conf);

            if (conf == 's' || conf == 'S') {
                printf("\nCerto, recome�ar!\n\n");
                x = 0; // Reinicia o loop
                break; // Sai do loop de confirma��o
            } else if (conf == 'n' || conf == 'N') {
                printf("\nObrigado pelo seu cadastro!\n\n");
                x = 1; // Finaliza
                break; // Sai do loop de confirma��o
            } else {
                printf("Resposta inv�lida! Por favor, digite S para sim ou N para n�o.\n");
            }
        }
        system("cls");
    } while (x != 1);

    system("pause");
    return 0;
}

int consulta() {
    setlocale(LC_ALL, "Portuguese"); // Defini��o da Linguagem
    char cpf[50];
    char arquivo[55]; // Tamanho ajustado para incluir ".txt"
    char conteudo[200];

    printf("Digite o CPF a ser consultado: \n");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt"); // Adiciona a extens�o .txt para abrir o arquivo correto

    FILE *file = fopen(arquivo, "r"); // Abre o arquivo
    if (file == NULL) {
        printf("\nN�o foi poss�vel encontrar o arquivo, N�O ENCONTRADO!\n\n");
        return -1; // Retorna erro
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }
    fclose(file);
    system("pause");
    return 0;
}

int deletar() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[50];
    char arquivo[55];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt");

    char conf; // Confirma��o
    while (1) {
        printf("\nTem certeza que quer deletar o usu�rio de CPF %s? (S/N): ", cpf);
        getchar(); // Limpa o buffer
        scanf(" %c", &conf); // O espa�o antes de %c limpa o buffer

        if (conf == 's' || conf == 'S') {
            if (remove(arquivo) == 0) {
                printf("\nArquivo removido com sucesso\n");
            } else {
                printf("Erro ao remover o arquivo!\n");
            }
            break; // Sai do loop de confirma��o
        } else if (conf == 'n' || conf == 'N') {
            printf("Opera��o cancelada!\n");
            break; // Sai do loop de confirma��o
        } else {
            printf("Resposta inv�lida! Por favor, digite S para sim ou N para n�o.\n");
        }
    }
    return 0;
}

int main() {
    int x = 0; // Armazenamento do valor inicial da letra X

    while (1) {
        system("cls"); // cls � para limpar as mensagens
        setlocale(LC_ALL, "Portuguese"); // Defini��o da Linguagem
        printf("\t Cart�rio da EBAC\n\n "); // In�cio do menu
        printf("Escolha uma das op��es a seguir:\n");
        printf("\t1 - Registrar nome:\n");
        printf("\t2 - Consultar nomes:\n");
        printf("\t3 - Deletar nomes:\n");
        printf("\t4 - Sair!\n\n");

        printf("Op��o: "); // Fim do menu
        scanf("%d", &x); // Armazenamento do valor digitado pelo usu�rio
        system("cls");

        switch (x) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("\nObrigado!!!\n\n");
                return 0;
            default:
                printf("Op��o inv�lida!!!\n"); // Fim da sele��o
                system("pause"); // Pausar o sistema, deixa mais organizado
        } // Fim da sele��o
    }
    return 0;		
}
