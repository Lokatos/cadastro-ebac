#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca para definir a localidade
#include <string.h> // Biblioteca responsável por cuidar das strings

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

        char conf; // Confirmação
        while (1) {
            printf("\nDeseja inserir outro usuário? (S/N): ");
            getchar(); // Limpa o buffer
            scanf("%c", &conf);

            if (conf == 's' || conf == 'S') {
                printf("\nCerto, recomeçar!\n\n");
                x = 0; // Reinicia o loop
                break; // Sai do loop de confirmação
            } else if (conf == 'n' || conf == 'N') {
                printf("\nObrigado pelo seu cadastro!\n\n");
                x = 1; // Finaliza
                break; // Sai do loop de confirmação
            } else {
                printf("Resposta inválida! Por favor, digite S para sim ou N para não.\n");
            }
        }
        system("cls");
    } while (x != 1);

    system("pause");
    return 0;
}

int consulta() {
    setlocale(LC_ALL, "Portuguese"); // Definição da Linguagem
    char cpf[50];
    char arquivo[55]; // Tamanho ajustado para incluir ".txt"
    char conteudo[200];

    printf("Digite o CPF a ser consultado: \n");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt"); // Adiciona a extensão .txt para abrir o arquivo correto

    FILE *file = fopen(arquivo, "r"); // Abre o arquivo
    if (file == NULL) {
        printf("\nNão foi possível encontrar o arquivo, NÃO ENCONTRADO!\n\n");
        return -1; // Retorna erro
    }

    printf("\nEssas são as informações do usuário:\n");
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
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt");

    char conf; // Confirmação
    while (1) {
        printf("\nTem certeza que quer deletar o usuário de CPF %s? (S/N): ", cpf);
        getchar(); // Limpa o buffer
        scanf(" %c", &conf); // O espaço antes de %c limpa o buffer

        if (conf == 's' || conf == 'S') {
            if (remove(arquivo) == 0) {
                printf("\nArquivo removido com sucesso\n");
            } else {
                printf("Erro ao remover o arquivo!\n");
            }
            break; // Sai do loop de confirmação
        } else if (conf == 'n' || conf == 'N') {
            printf("Operação cancelada!\n");
            break; // Sai do loop de confirmação
        } else {
            printf("Resposta inválida! Por favor, digite S para sim ou N para não.\n");
        }
    }
    return 0;
}

int main() {
    int x = 0; // Armazenamento do valor inicial da letra X

    while (1) {
        system("cls"); // cls é para limpar as mensagens
        setlocale(LC_ALL, "Portuguese"); // Definição da Linguagem
        printf("\t Cartório da EBAC\n\n "); // Início do menu
        printf("Escolha uma das opções a seguir:\n");
        printf("\t1 - Registrar nome:\n");
        printf("\t2 - Consultar nomes:\n");
        printf("\t3 - Deletar nomes:\n");
        printf("\t4 - Sair!\n\n");

        printf("Opção: "); // Fim do menu
        scanf("%d", &x); // Armazenamento do valor digitado pelo usuário
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
                printf("Opção inválida!!!\n"); // Fim da seleção
                system("pause"); // Pausar o sistema, deixa mais organizado
        } // Fim da seleção
    }
    return 0;		
}
